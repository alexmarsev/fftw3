/*
 * Copyright (c) 2002 Matteo Frigo
 * Copyright (c) 2002 Steven G. Johnson
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

/* $Id: problem.c,v 1.4 2002-08-01 07:03:18 stevenj Exp $ */

#include "ifftw.h"

/* constructor */
problem *X(mkproblem)(size_t sz, const problem_adt *adt)
{
     problem *p = (problem *)fftw_malloc(sz, PROBLEMS);

     p->adt = adt;
     p->refcnt = 1;
     return p;
}

/* destructor */
void X(problem_destroy)(problem *ego)
{
     if ((--ego->refcnt) == 0)
	  DESTROY(ego);
}

/* ``copy'' the problem */
problem *X(problem_dup)(problem *ego)
{
     ++ego->refcnt;
     return ego;
}

