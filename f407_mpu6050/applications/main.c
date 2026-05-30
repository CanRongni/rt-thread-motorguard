/*
 * Copyright (c) 2006-2026, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2026-05-23     RT-Thread    first version
 * 2026-05-29     MotorGuard   v1.0 integration
 */

#include <rtthread.h>

#include "mg_err.h"

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

/* ==================== I2C总线配置 ==================== */
#define SENSOR_I2C_BUS    "i2c1"

int main(void)
{
    int ret;

    rt_kprintf("\r\n");
    rt_kprintf("============================================\r\n");
    rt_kprintf("  MotorGuard Pro v1.0 - Basic Monitoring\r\n");
    rt_kprintf("  RT-Thread + MPU6050 Vibration Sensor\r\n");
    rt_kprintf("============================================\r\n");
    rt_kprintf("\r\n");



    return RT_EOK;
}
