/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to 2013 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $OSPL_HOME/LICENSE 
 *
 *   for full copyright notice and license terms. 
 *
 */
#ifndef U_SCHEDULER_H
#define U_SCHEDULER_H

#if defined (__cplusplus)
extern "C" {
#endif

#include "os_thread.h"
#include "os_process.h"
#include "u_types.h"
#include "v_scheduler.h"
#include "os_if.h"

#ifdef OSPL_BUILD_USER
#define OS_API OS_API_EXPORT
#else
#define OS_API OS_API_IMPORT
#endif
/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

OS_API u_result
u_threadAttrInit(
    struct v_schedulePolicy *v_schedParam,
    os_threadAttr *os_threadParam);

OS_API u_result 
u_procAttrInit(
    struct v_schedulePolicy *v_schedParam,
    os_procAttr *os_procParam);

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif /* U_SCHEDULER_H */
