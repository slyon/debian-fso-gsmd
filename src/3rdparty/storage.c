/*
 *
 *  oFono - Open Source Telephony
 *
 *  Copyright (C) 2008-2009  Intel Corporation. All rights reserved.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef _GNU_SOURCE
 #define _GNU_SOURCE
#endif
#include <string.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

#include <glib.h>

#include "storage.h"

int create_dirs(const char *filename, const mode_t mode)
{
	struct stat st;
	char *dir;
	const char *prev, *next;
	int err;

	err = stat(filename, &st);
	if (!err && S_ISREG(st.st_mode))
		return 0;

	dir = g_malloc(strlen(filename) + 1);
	strcpy(dir, "/");

	for (prev = filename; (next = strchr(prev + 1, '/')); prev = next)
		if (next > prev + 1) {
			strncat(dir, prev + 1, next - prev);

			if (mkdir(dir, mode) && errno != EEXIST) {
				g_free(dir);
				return -1;
			}
		}

	g_free(dir);
	return 0;
}

ssize_t read_file(unsigned char *buffer, size_t len,
			const char *path_fmt, ...) {
	va_list ap;
	char *path;
	ssize_t r;
	int fd;

	va_start(ap, path_fmt);
	path = g_strdup_vprintf(path_fmt, ap);
	va_end(ap);

	fd = TFR(open(path, O_RDONLY));

	g_free(path);

	if (fd == -1)
		return -1;

	r = TFR(read(fd, buffer, len));

	TFR(close(fd));

	return r;
}

ssize_t write_file(const unsigned char *buffer, size_t len, mode_t mode,
			const char *path_fmt, ...) {
	va_list ap;
	char *path;
	ssize_t r;
	int fd;

	va_start(ap, path_fmt);
	path = g_strdup_vprintf(path_fmt, ap);
	va_end(ap);

	if (create_dirs(path, mode | S_IXUSR) != 0) {
		g_free(path);
		return -1;
	}

	fd = TFR(open(path, O_WRONLY | O_CREAT | O_TRUNC, mode));
	if (fd == -1) {
		g_free(path);
		return -1;
	}

	r = TFR(write(fd, buffer, len));

	TFR(close(fd));

	if (r != (ssize_t) len) {
		unlink(path);
		r = -1;
	}

	g_free(path);
	return r;
}
