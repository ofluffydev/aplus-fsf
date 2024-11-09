/*****************************************************************************/
/*                                                                           */
/* Copyright (c) 1989-2008 Morgan Stanley All rights reserved.*/
/* See .../src/LICENSE for terms of distribution.                           */
/*                                                                           */
/*                                                                           */
/*****************************************************************************/
/* contributed by Daniel F. Fisher */

/* header file inclusions */
#include <dap/node.h>
#include <dap/hash.h>

/* external function definitions */
void *
hashremove(struct hash * p, void *key)
{
  if ((p != (struct hash *) (0))
      && (key != (void *) (0))) {
    struct node *hnp;
    struct node *np;

    hnp = p->tbl + ((*(p->hashfunc)) (key) % p->tblsz);
    if ((np = (*(p->find)) (hnp, key)) != (struct node *) (0)) {
      void *oldval = (*(p->value)) (np);
      (*(p->remove)) (np);
      return oldval;
    }
  }
  return (void *) (0);
}
