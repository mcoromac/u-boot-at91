#include <common.h>
#include <debug_uart.h>
#include <asm/io.h>
#include <asm/arch/atmel_pio4.h>
#include <asm/arch/clk.h>
#include <asm/arch/gpio.h>
#include <asm/arch/sama5d2.h>

/*#include <asm/arch/at91_common.h>
#include <asm/arch/at91_rstc.h>
#include <asm/arch/sama5d3_smc.h>
#include <asm/arch/atmel_mpddrc.h>
#include <asm/arch/at91_wdt.h>*/
DECLARE_GLOBAL_DATA_PTR;

int dram_init(void)
{
	gd->ram_size = get_ram_size((void *)CONFIG_SYS_SDRAM_BASE,
				    CONFIG_SYS_SDRAM_SIZE);
	return 0;
}

#ifdef CONFIG_DEBUG_UART_BOARD_INIT
static void board_uart1_hw_init(void)
{
	atmel_pio4_set_a_periph(AT91_PIO_PORTA, 23, 1);	/* URXD */
	atmel_pio4_set_a_periph(AT91_PIO_PORTA, 24, 0);	/* UTXD */

	at91_periph_clk_enable(ATMEL_ID_FLEXCOM1);
}

void board_debug_uart_init(void)
{
	board_uart1_hw_init();
	/*at91_seriald_hw_init();*/
}
#endif

#ifdef CONFIG_BOARD_EARLY_INIT_F
int board_early_init_f(void)
{
#ifdef CONFIG_DEBUG_UART
	debug_uart_init();
#endif

	return 0;
}
#endif

int board_init(void)
{
	/* address of boot parameters */
	gd->bd->bi_boot_params = CONFIG_SYS_SDRAM_BASE + 0x100;

#ifdef CONFIG_CMD_USB
	board_usb_hw_init();
#endif

	return 0;
}

#ifdef CONFIG_MISC_INIT_R
int misc_init_r(void)
{
	return 0;
}
#endif
