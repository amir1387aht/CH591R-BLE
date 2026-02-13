#include "CONFIG.h"
#include "HAL.h"
#include "ble/gattprofile.h"
#include "ble/ble.h"
#include "drivers/ws2812b.h"

__HIGH_CODE
__attribute__((noinline))
void Main_Circulation()
{
    while(1)
    {
        TMOS_SystemProcess();
    }
}

int main(void)
{
    SetSysClock(CLK_SOURCE_PLL_60MHz);

#ifdef DEBUG
    GPIOA_SetBits(bTXD1);
    GPIOA_ModeCfg(bTXD1, GPIO_ModeOut_PP_5mA);
    UART1_DefInit();
#endif

    // Gnd for PA13(Remove these two lines if you connected the gnd of led to gnd of board)
    GPIOA_ModeCfg(GPIO_Pin_13, GPIO_ModeOut_PP_20mA);
    GPIOA_ResetBits(GPIO_Pin_13);
    
    // Initialize single LED on GPIOA Pin 12
    led = ws2812b_init(WS2812B_PORT_A, GPIO_Pin_12, 1);
    
    if (led == NULL) {
        while(1);
    }
    
    ws2812b_clear(led, 1);
    DelayMs(500);

    CH59x_BLEInit();
    HAL_Init();
    GAPRole_PeripheralInit();
    Peripheral_Init();
    Main_Circulation();
}