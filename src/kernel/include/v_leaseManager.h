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
#ifndef V_LEASEMANAGER_H
#define V_LEASEMANAGER_H

/** \file kernel/include/v_leaseManager.h
 * \brief This file defines the interface of the lease manager. For the design
 * See the v_leaseManager.c file
 */

#if defined (__cplusplus)
extern "C" {
#endif
#include "os_if.h"
#include "v_event.h"

#ifdef OSPL_BUILD_KERNEL
#define OS_API OS_API_EXPORT
#else
#define OS_API OS_API_IMPORT
#endif
/* !!!!!!!!NOTE From here no more includes are allowed!!!!!!! */

/**
 * \brief The <code>v_leaseManager</code> cast method.
 *
 * This method casts an object to a <code>v_leaseManager</code> object.
 * Before the cast is performed, if compiled with the NDEBUG flag not set,
 * the type of the object is checked to be <code>v_leaseManager</code> or
 * one of its subclasses.
 */
#define v_leaseManager(o) (C_CAST(o,v_leaseManager))

/**
 * \brief This is the main routine of the leaseManager which is called
 * when the lease manager thread is spawned. The function acts based on
 * the 'next expiry time' of the lease manager. It waits until that moment
 * is reached and then collects any expired leases, and performs the registered
 * action routine for each one.
 * The main routine will run until the quit attribute of the lease manager is set
 * to FALSE, which happens when it is notified by a termination event.
 *
 * \param _this The leaseManager to use within this function.
 */
OS_API void
v_leaseManagerMain(
    v_leaseManager _this);

/**
 * \brief This operation will notify the leaseManager of a change, which can be
 * a change to the set of observed leases or a terminate event.
 *
 * \param _this The leaseManager to use within this function.
 * \param lease The lease involved in the notify or NULL if no lease was involved
 * \param event The event kind. Only V_EVENT_LEASE_RENEWED and V_EVENT_TERMINATE
 *              are processed, other events are ignored.
 */
OS_API c_bool
v_leaseManagerNotify(
    v_leaseManager _this,
    v_lease lease,
    v_eventKind event);

#undef OS_API

#if defined (__cplusplus)
}
#endif

#endif /* V_LEASEMANAGER_H */
