#ifndef __DRV_MPU6050_H__
#define __DRV_MPU6050_H__

#include <rtthread.h>
#include <rtdevice.h>

/* ==================== 寄存器地图 ==================== */
/* MPU6050 7位I2C地址,AD0接地=0x68,接高=0x69 */
#define MPU6050_ADDR            0x68

#define MPU_REG_SMPLRT_DIV       0x19  /* 采样率分频 */
#define MPU_REG_CONFIG           0x1A  /* DLPF 配置 */
#define MPU_REG_GYRO_CONFIG      0x1B  /* 陀螺仪量程 */
#define MPU6050_REG_ACCEL_CONFIG 0x1C  /* 加速度计量程 */
#define MPU6050_REG_ACCEL_XOUT_H 0x3B  /* 数据区起点,往后连续14字节 */
#define MPU_REG_TEMP_OUT_H       0x41  /* 温度高字节 */
#define MPU_REG_GYRO_XOUT_H      0x43  /* 陀螺仪数据起点 */
#define MPU6050_REG_PWR_MGMT_1   0x6B  /* 电源管理1 */
#define MPU6050_REG_WHO_AM_I     0x75  /* 设备ID,应返回 0x68 */
#define MPU6050_WHO_AM_I_VALUE   0x68
/* ==================== 量程枚举 ==================== */
typedef enum {
    MPU_ACCEL_FS_2G  = 0,   /* 灵敏度 16384 LSB/g */
    MPU_ACCEL_FS_4G  = 1,   /* 灵敏度  8192 LSB/g */
    MPU_ACCEL_FS_8G  = 2,   /* 灵敏度  4096 LSB/g */
    MPU_ACCEL_FS_16G = 3,   /* 灵敏度  2048 LSB/g */
} mpu_accel_fs_t;

typedef enum {
    MPU_GYRO_FS_250  = 0,   /* 灵敏度 131.0 LSB/(°/s) */
    MPU_GYRO_FS_500  = 1,   /* 灵敏度  65.5 LSB/(°/s) */
    MPU_GYRO_FS_1000 = 2,   /* 灵敏度  32.8 LSB/(°/s) */
    MPU_GYRO_FS_2000 = 3,   /* 灵敏度  16.4 LSB/(°/s) */
} mpu_gyro_fs_t;

/* ==================== 数据结构 ==================== */
typedef struct {
    int16_t ax, ay, az;     /* 加速度原始值 */
    int16_t gx, gy, gz;     /* 陀螺仪原始值 */
    int16_t temp_raw;       /* 温度原始值 */
} mpu_raw_data_t;

typedef struct {
    float ax_g, ay_g, az_g;     /* 加速度,单位 g */
    float gx_dps, gy_dps, gz_dps;/* 角速度,单位 °/s */
    float temp_c;                /* 温度,单位 °C */
} mpu_data_t;

/* ==================== 对外接口 ==================== */
int mpu6050_init(const char *i2c_bus_name);
int mpu6050_read_raw(mpu_raw_data_t *out);
int mpu6050_read_data(mpu_data_t *out);
int mpu6050_set_accel_fs(mpu_accel_fs_t fs);
int mpu6050_set_gyro_fs(mpu_gyro_fs_t fs);

#endif


