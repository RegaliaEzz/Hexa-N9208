/*
 *  Architecture specific OF callbacks.
 *
 *  Copyright (C) 2011 Texas Instruments Incorporated
 *  Author: Mark Salter <msalter@redhat.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 */
#include <linux/init.h>
#include <linux/of.h>
#include <linux/of_fdt.h>
#include <linux/memblock.h>

void __init early_init_devtree(void *params)
{
	/* Setup flat device-tree pointer */
	initial_boot_params = params;

	/* Retrieve various informations from the /chosen node of the
	 * device-tree, including the platform type, initrd location and
	 * size and more ...
	 */
	of_scan_flat_dt(early_init_dt_scan_chosen, c6x_command_line);

	/* Scan memory nodes and rebuild MEMBLOCKs */
	of_scan_flat_dt(early_init_dt_scan_root, NULL);
	of_scan_flat_dt(early_init_dt_scan_memory, NULL);
}

void __init early_init_dt_add_memory_arch(u64 base, u64 size)
{
	c6x_add_memory(base, size);
}
