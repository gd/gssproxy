/*
   GSS-PROXY

   Copyright (C) 2011 Red Hat, Inc.
   Copyright (C) 2011 Simo Sorce <simo.sorce@redhat.com>
   Copyright (C) 2013 Guenther Deschner <guenther.deschner@redhat.com>

   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
   THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   DEALINGS IN THE SOFTWARE.
*/

#include "config.h"
#include <stdint.h>
#include <stdbool.h>

#include "gp_debug.h"
#include "gp_rpc_print.h"

extern int gp_debug;

#ifdef HAVE_NDR_GSSPROXY

#include <gen_ndr/ndr_gssproxy.h>

#define GP_PRINT_FUNC(name) \
void gp_print_ ## name(uint32_t flags, uint32_t opcode, void *data) \
{\
    char *s = NULL; \
    TALLOC_CTX *mem_ctx; \
    void *in, *out; \
    if (!gp_debug) { return; } \
    mem_ctx = talloc_init("gp_print_" # name); \
    if (mem_ctx == NULL) { return; }; \
    switch (flags) { \
    case GP_PRINT_IN: \
        in = data; \
        s = NDR_PRINT_STRUCT_STRING(mem_ctx, gssx_arg_ ## name, in); \
        if (s) { \
            GPDEBUG("%s\n", s); \
        } \
        break; \
    case GP_PRINT_OUT: \
        out = data; \
        s = NDR_PRINT_STRUCT_STRING(mem_ctx, gssx_res_ ## name, out); \
        if (s) { \
            GPDEBUG("%s\n", s); \
        } \
        break; \
    default: \
        break; \
    } \
    talloc_free(mem_ctx); \
}
#else
#define GP_PRINT_FUNC(name) \
void gp_print_ ## name(uint32_t flags, uint32_t opcode, void *data) {}
#endif /* HAVE_NDR_GSSPROXY */

GP_PRINT_FUNC(acquire_cred)
GP_PRINT_FUNC(init_sec_context)
GP_PRINT_FUNC(accept_sec_context)
GP_PRINT_FUNC(indicate_mechs)
GP_PRINT_FUNC(release_handle)
GP_PRINT_FUNC(import_and_canon_name)
GP_PRINT_FUNC(get_call_context)
GP_PRINT_FUNC(export_cred)
GP_PRINT_FUNC(import_cred)
GP_PRINT_FUNC(store_cred)
GP_PRINT_FUNC(get_mic)
GP_PRINT_FUNC(verify_mic)
GP_PRINT_FUNC(wrap)
GP_PRINT_FUNC(unwrap)
GP_PRINT_FUNC(wrap_size_limit)
