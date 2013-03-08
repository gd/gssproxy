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

#define GP_PRINT_IN 1
#define GP_PRINT_OUT 2

#define GP_PRINT_PROTO(name) \
void gp_print_ ## name(uint32_t flags, uint32_t opcode, void *data);

GP_PRINT_PROTO(indicate_mechs)
GP_PRINT_PROTO(acquire_cred)
GP_PRINT_PROTO(init_sec_context)
GP_PRINT_PROTO(accept_sec_context)
GP_PRINT_PROTO(indicate_mechs)
GP_PRINT_PROTO(release_handle)
GP_PRINT_PROTO(import_and_canon_name)
GP_PRINT_PROTO(get_call_context)
GP_PRINT_PROTO(export_cred)
GP_PRINT_PROTO(import_cred)
GP_PRINT_PROTO(store_cred)
GP_PRINT_PROTO(get_mic)
GP_PRINT_PROTO(verify_mic)
GP_PRINT_PROTO(wrap)
GP_PRINT_PROTO(unwrap)
GP_PRINT_PROTO(wrap_size_limit)
