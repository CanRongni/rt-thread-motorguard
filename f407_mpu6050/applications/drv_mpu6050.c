#include <rtthread.h>
#include <rtdevice.h>
#include "drv_mpu6050.h"
#include "mg_err.h"



static struct rt_i2c_bus_device *g_i2c_bus = RT_NULL;

static int mpu6050_write_reg(uint8_t reg, uint8_t val)
{
    uint8_t buf[2];
    buf[0] = reg;
    buf[1] = val;

    struct rt_i2c_msg msg;
    msg.addr  = MPU6050_ADDR;
    msg.flags = RT_I2C_WR ;
    msg.len   = 2;
    msg.buf   = buf;

    if(rt_i2c_transfer(g_i2c_bus, &msg, 1) != 1)
    {
        return  MG_EIO;
    }
    return MG_EOK;
}

static int mpu6050_read_reg(uint8_t reg,uint8_t val)
{
    uint8_t buf[2];
    buf[0] = reg ;
    buf[1] = val ;

    struct rt_i2c_msg msg;
    msg.addr  = MPU6050_ADDR;
    msg.flags = RT_I2C_RD ;
    msg.len   = 2;
    msg.buf   = buf;

    if(rt_i2c_transfer(g_i2c_bus, &msg, 1) != 1)
    {
          return  MG_EIO;
    }
    return MG_EOK;

}

static int mpu6050_read_regs(struct rt_i2c_bus_device *bus, rt_uint8_t len, rt_uint8_t *buf)
{
    struct rt_i2c_msg msgs;

    msgs.addr =  MPU6050_ADDR;
    msgs.flags = RT_I2C_RD;
    msgs.buf = buf;
    msgs.len = len;

    /* 调用I2C设备接口传输数据 */
    if (rt_i2c_transfer(bus, &msgs, 1) == 1)
    {
        return RT_EOK;
    }
    else
    {
        return -RT_ERROR;
    }
}


int mpu6050_init(const char *i2c_bus_name)
{
    g_i2c_bus = rt_i2c_bus_device_find(i2c_bus_name);

    if (g_i2c_bus == RT_NULL)
    {
        rt_kprintf("can not find %s\n", i2c_bus_name);
        return -RT_ERROR;
    }

    rt_kprintf("find %s success\n", i2c_bus_name);

    return RT_EOK;
}
