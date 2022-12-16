#include <stdio.h>

// Listing I - Pre-emptive Priority with Interrupt
static void JobA(){...};
static void JobB(){...};
static void JobC(){...};
const TickType_t xPeriodB = 10;
const TickType_t xPeriodC = 5;

static void isr_hdler(void *)
{
    JobA();
}

static void per_taskB(void *arg)
{
    TickType_t xLastWakeTime;

    for (;;)
    {
        xLastWakeTime = xTaskGetTickCount();
        JobB();
        vTaskDelayUntil(&xLastWakeTime, xPeriodB);
        19
    }
}

static void per_taskC(void *arg)
{
    TickType_t xLastWakeTime;
    for (;;)
    {
        xLastWakeTime = xTaskGetTickCount();
        JobB();
        vTaskDelayUntil(&xLastWakeTime, xPeriodC);
        30
    }
}

void app_main(void)
{
    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_INTR_HIGH_LEVEL;
    io_conf.pin_bit_mask = GPIO_PIN_0;
    io_conf.mode = GPIO_MODE_INPUT;
    gpio_config(&io_conf);
    xTaskCreate(per_taskB, "B", 2048, NULL, 10, NULL);
    xTaskCreate(per_taskC, "C", 2048, NULL, 11, NULL);
    gpio_install_isr_service(0);
    gpio_isr_handler_add(GPIO_NUM_0, isr_hdler, NULL);
}

// Listing II - Cyclic Executive

static void JobA(){...};
static void JobB(){...};
static void JobC(){...};
const TickType_t xSlot = 5;

static void cyclicx(void *arg)
{
    TickType_t xLastWakeTime;
    for (;;)
    {
        // Slot 1 of 2
        xLastWakeTime = xTaskGetTickCount();
        if (gpio_get_level(GPIO_INPUT_0))
            JobA();
        JobC();
        vTaskDelayUntil(&xLastWakeTime, xSlot);
        // Slot 2 of 2
        xLastWakeTime = xTaskGetTickCount();
        if (gpio_get_level(GPIO_NUM_0))
            JobA();
        JobB();
        JobC();
        vTaskDelayUntil(&xLastWakeTime, xSlot);
    }
}

void app_main(void)
{
    gpio_config_t io_conf;
    io_conf.pin_bit_mask = GPIO_INPUT_IO_0;
    io_conf.mode = GPIO_MODE_INPUT;
    gpio_config(&io_conf);
    for (;;)
    {
        cyclicx();
    }
}
