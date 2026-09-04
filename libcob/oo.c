/*
   Copyright (C) 2002-2012, 2014-2020, 2022-2025 Free Software Foundation, Inc.
   Written by Keisuke Nishida, Roger While, Simon Sobisch, Ron Norman,
   Edwart Hard

   This file is part of GnuCOBOL.

   The GnuCOBOL runtime library is free software: you can redistribute it
   and/or modify it under the terms of the GNU Lesser General Public License
   as published by the Free Software Foundation, either version 3 of the
   License, or (at your option) any later version.

   GnuCOBOL is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with GnuCOBOL.  If not, see <https://www.gnu.org/licenses/>.
*/


#include "common.h"
// #include "config.h"

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

#ifdef	HAVE_LOCALE_H
#include <locale.h>
#endif

/* include internal and external libcob definitions, forcing exports */
#define	COB_LIB_EXPIMP
// #include "coblocal.h"

struct cob_factory_obj*
cob_load_class (const char* class_name) {
    struct cob_factory_obj* class_obj;
    void (*cls) ();

    const size_t len = strlen(class_name);
    char* class_name_ = cob_malloc(len + 2);

    memcpy(class_name_, class_name, len);
    strcat(class_name_, "_");
    class_name_[len + 2] = '\0';

    printf ("class_name_: %s\n", class_name_);
    cls = cob_resolve_oo_class (class_name_);

    printf ("calling cls()\n");
    cls();

    class_obj = (struct cob_factory_obj*) cob_malloc (sizeof(struct cob_factory_obj));
    class_obj->class_name = class_name;

    return class_obj;
    // can return a pointer to a cob_factory_obj (handle to a class object)
    // to be defined inside common.h    
}