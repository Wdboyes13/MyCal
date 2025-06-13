/*
MyCal - A Planner & Calendar app with a UI
Copyright (C) 2025  Wdboyes13

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifdef __APPLE__
.section __TEXT, __my_info
                     .align 2
#else
.section .rodata
    .align 4
#endif

                     .global _my_email _my_email
    :.asciz "Email: willdev2025@icloud.com".global _proj_site _proj_site
    :.asciz "Website: https://github.com/Wdboyes13/MyCal"

                     .global _my_uname _my_uname
    :.asciz "GitHub Username: Wdboyes13".global _license _license
    :.asciz "License: GNU General Public License v3"
