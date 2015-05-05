/*
 * ReactOS Application
 * Copyright (C) 2008-2009 :P Davy Bartoloni :P
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* $Id: firstapp.c 2008-28-12 21:17:12 $
 *
 * COPYRIGHT:   See COPYING in the top level directory
 * PROJECT:     ReactOS Simple COMPILER-TEST
 * FILE:        base\setup\firstapp.c
 * PROGRAMMERS: Davy Bartoloni <davy@bartoloni.org>
 */


#include <windows.h> // managing windows...
#include <tchar.h>   // for TEXT function ( unicode strings )

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
     //this is the first Message BOX...
     MessageBox(
      0,
      TEXT("This is my first Reactos-Application"),
      TEXT("This is a MESSAGEBOX"),
       MB_OK
      );

     //and this is the second... the code is the same, but on a single-line.
     MessageBox(0,TEXT("This is another MESSAGEBOX"),TEXT("Press OK..."), MB_OK);

return(0);
}