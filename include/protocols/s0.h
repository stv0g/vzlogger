/**
 * S0 Hutschienenzähler directly connected to an rs232 port
 *
 * @package vzlogger
 * @copyright Copyright (c) 2011, The volkszaehler.org project
 * @license http://www.gnu.org/licenses/gpl.txt GNU Public License
 * @author Steffen Vogel <info@steffenvogel.de>
 */
/*
 * This file is part of volkzaehler.org
 *
 * volkzaehler.org is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * volkzaehler.org is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with volkszaehler.org. If not, see <http://www.gnu.org/licenses/>.
 */
 
#ifndef _S0_H_
#define _S0_H_

#include <termios.h>

typedef struct {
	char *device;
	int resolution;

	int fd;	/* file descriptor of port */
	struct termios old_tio;	/* required to reset port */
} meter_handle_s0_t;

/* forward declarations */
struct meter;
struct reading;

int meter_init_s0(struct meter *mtr, list_t options);
void meter_free_s0(struct meter *mtr);
int meter_open_s0(struct meter *mtr);
int meter_close_s0(struct meter *mtr);
size_t meter_read_s0(struct meter *mtr, struct reading *rds, size_t n);

#endif /* _S0_H_ */
