/*
 * Copyright (c) 2014 Dave Vasilevsky <dave@vasilevsky.ca>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef SQFS_LIST_H
#define SQFS_LIST_H

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

struct sqfs_list_node;
typedef struct sqfs_list_node sqfs_list_node;

/* Singly-linked list */
typedef struct {
  sqfs_list_node *first, *last;
} sqfs_list;

void sqfs_list_create(sqfs_list *list);
void sqfs_list_clear(sqfs_list *list);

/* Check if we're empty */
bool sqfs_list_empty(sqfs_list *list);

/* Shift the first item out, return NULL if empty. Caller should free the
   item when done. */
void *sqfs_list_shift(sqfs_list *list);
void *sqfs_list_first(sqfs_list *list);

/* `item' should be allocated, free-able with free() */
sqfs_err sqfs_list_append(sqfs_list *list, void *item);

/* Splice a list into the beginning of an existing list. Clears the source
   list. */
sqfs_err sqfs_list_splice_start(sqfs_list *src, sqfs_list *dst);

#ifdef __cplusplus
}
#endif

#endif
