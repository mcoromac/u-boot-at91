/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Common part of configuration settings for the AT91 SAMA5 board.
 *
 * Copyright (C) 2015 Atmel Corporation
 *		      Josh Wu <josh.wu@atmel.com>
 */

#ifndef __AT91_SAMA5_COMMON_H
#define __AT91_SAMA5_COMMON_H

/* ARM asynchronous clock */
#define CONFIG_SYS_AT91_SLOW_CLOCK      32768
#define CONFIG_SYS_AT91_MAIN_CLOCK      12000000 /* from 12 MHz crystal */

#define CONFIG_ARCH_CPU_INIT

#ifndef CONFIG_SPL_BUILD
#define CONFIG_SKIP_LOWLEVEL_INIT
#endif

/* general purpose I/O */
#ifndef CONFIG_DM_GPIO
#define CONFIG_AT91_GPIO
#endif


/*
 * BOOTP options
 */
#define CONFIG_BOOTP_BOOTFILESIZE

/*
 * Command line configuration.
 */

<<<<<<< HEAD
#if defined(CONFIG_SYS_USE_MMC) || defined(CONFIG_SD_BOOT)
=======
#ifdef CONFIG_SD_BOOT
>>>>>>> 1e7d2e5973c1fb780e55e28a801c6c574158ac14

#ifdef CONFIG_ENV_IS_IN_MMC
/* Use raw reserved sectors to save environment */
#define CONFIG_ENV_OFFSET		0x2000
#define CONFIG_ENV_SIZE			0x1000
#define CONFIG_SYS_MMC_ENV_DEV		0
#else
/* u-boot env in sd/mmc card */
#define CONFIG_ENV_SIZE		0x4000
#endif

#define CONFIG_BOOTCOMMAND	"if test ! -n ${dtb_name}; then "	\
				    "setenv dtb_name at91-${board_name}.dtb; " \
				"fi; "					\
				"fatload mmc 0:1 0x21000000 ${dtb_name}; " \
				"fatload mmc 0:1 0x22000000 zImage; "	\
				"bootz 0x22000000 - 0x21000000"

#else
<<<<<<< HEAD
#define CONFIG_BOOTARGS							\
	"console=ttyS0,115200 earlyprintk "				\
	"mtdparts=atmel_nand:256k(bootstrap)ro,768k(uboot)ro,"		\
	"256K(env_redundant),256k(env),"				\
	"512k(dtb),6M(kernel)ro,-(rootfs) "				\
	"rootfstype=ubifs ubi.mtd=6 root=ubi0:rootfs"

#if defined(CONFIG_SYS_USE_NANDFLASH) || defined(CONFIG_NAND_BOOT)
/* u-boot env in nand flash */
#define CONFIG_ENV_IS_IN_NAND
=======

#ifdef CONFIG_NAND_BOOT
/* u-boot env in nand flash */
>>>>>>> 1e7d2e5973c1fb780e55e28a801c6c574158ac14
#define CONFIG_ENV_OFFSET		0x140000
#define CONFIG_ENV_OFFSET_REDUND	0x100000
#define CONFIG_ENV_SIZE			0x20000
#define CONFIG_BOOTCOMMAND		"nand read 0x21000000 0x180000 0x80000;"	\
					"nand read 0x22000000 0x200000 0x600000;"	\
					"bootz 0x22000000 - 0x21000000"
#elif CONFIG_SPI_BOOT
/* u-boot env in serial flash, by default is bus 0 and cs 0 */
<<<<<<< HEAD
#define CONFIG_ENV_IS_IN_SPI_FLASH
#ifdef CONFIG_QSPI_BOOT
#define CONFIG_ENV_OFFSET		0xb0000
#define CONFIG_ENV_SIZE			0x10000
#define CONFIG_ENV_SECT_SIZE		0x10000
#define CONFIG_BOOTCOMMAND		"sf probe 0; "				\
					"sf read 0x21000000 0xc0000 0x20000; "	\
					"sf read 0x22000000 0xe0000 0x400000; "	\
					"bootz 0x22000000 - 0x21000000"
#else
=======
>>>>>>> 1e7d2e5973c1fb780e55e28a801c6c574158ac14
#define CONFIG_ENV_OFFSET		0x6000
#define CONFIG_ENV_SIZE			0x2000
#define CONFIG_ENV_SECT_SIZE		0x1000
#define CONFIG_BOOTCOMMAND		"sf probe 0; "				\
					"sf read 0x21000000 0x60000 0xc000; "	\
					"sf read 0x22000000 0x6c000 0x394000; "	\
					"bootz 0x22000000 - 0x21000000"
#elif CONFIG_QSPI_BOOT
#define CONFIG_ENV_OFFSET		0x140000
#define CONFIG_ENV_SIZE			0x20000
#define CONFIG_ENV_SECT_SIZE		0x1000
#define CONFIG_BOOTCOMMAND		"sf probe 0; "					\
					"sf read 0x21000000 0x180000 0x80000; "		\
					"sf read 0x22000000 0x200000 0x600000; "	\
					"bootz 0x22000000 - 0x21000000"
#endif

#endif

<<<<<<< HEAD
#endif

#define CONFIG_BAUDRATE			115200

#define CONFIG_SYS_CBSIZE		256
#define CONFIG_SYS_MAXARGS		16
#define CONFIG_SYS_LONGHELP
#define CONFIG_CMDLINE_EDITING
#define CONFIG_AUTO_COMPLETE

=======
>>>>>>> 1e7d2e5973c1fb780e55e28a801c6c574158ac14
/* Size of malloc() pool */
#define CONFIG_SYS_MALLOC_LEN		(4 * 1024 * 1024)

#endif
