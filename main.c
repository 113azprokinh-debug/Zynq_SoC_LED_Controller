#include <stdio.h>
#include "xil_printf.h"
#include "xgpio.h"
#include "xparameters.h"
#include "sleep.h"

#define GPIO_DEVICE_ID  XPAR_AXI_GPIO_0_DEVICE_ID
#define LED_CHANNEL     1

int main()
{
    XGpio Gpio;
    int status;

    print("Khoi tao he thong Zynq SoC \n\r");


    status = XGpio_Initialize(&Gpio, GPIO_DEVICE_ID);
    if (status != XST_SUCCESS) {
        print("Khoi tao GPIO That Bai!\n\r");
        return XST_FAILURE;
    }


    XGpio_SetDataDirection(&Gpio, LED_CHANNEL, 0x00);

    print("Khoi tao thanh cong! Bat dau nhap nhay LED...\n\r");

    while(1) {

        XGpio_DiscreteWrite(&Gpio, LED_CHANNEL, 0xFF);
        sleep(1);

        XGpio_DiscreteWrite(&Gpio, LED_CHANNEL, 0x00);
        sleep(1);
    }

    return 0;
}
