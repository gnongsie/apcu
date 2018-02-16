/*
  +----------------------------------------------------------------------+
  | APC                                                                  |
  +----------------------------------------------------------------------+
  | Copyright (c) 2006-2011 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Authors: Pierre Joye <pierre@php.net>                                |
  +----------------------------------------------------------------------+
 */
/* $Id$ */

#include <php.h>

#ifdef APC_SRWLOCK_KERNEL
#include "apc_windows_srwlock_kernel.h"

apc_windows_cs_rwlock_t *apc_windows_cs_create(apc_windows_cs_rwlock_t *lock) 
{
	InitializeSRWLock(lock);

	return lock;
}

void apc_windows_cs_destroy(apc_windows_cs_rwlock_t *lock)
{
	/* pass */
	return;
}

void apc_windows_cs_lock(apc_windows_cs_rwlock_t *lock)
{
	AcquireSRWLockExclusive(lock);
}

void apc_windows_cs_rdlock(apc_windows_cs_rwlock_t *lock)
{
	AcquireSRWLockShared(lock);
}

void apc_windows_cs_unlock_rd(apc_windows_cs_rwlock_t *lock)
{
	ReleaseSRWLockShared(lock);
}

void apc_windows_cs_unlock_wr(apc_windows_cs_rwlock_t *lock)
{
	ReleaseSRWLockExclusive(lock);
}

#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim>600: expandtab sw=4 ts=4 sts=4 fdm=marker
 * vim<600: expandtab sw=4 ts=4 sts=4
 */
