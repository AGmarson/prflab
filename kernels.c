/********************************************************
 * Kernels to be optimized for the OS&C prflab.
 * Acknowledgment: This lab is an extended version of the
 * CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "smooth.h" // helper functions for naive_smooth
#include "blend.h"  // helper functions for naive_blend
/*
 * Please fill in the following struct
 */
student_t student = {
    "tcla",                     /* ITU alias */
    "Thor Liam Møller Clausen", /* Full name */
    "tcla@itu.dk",              /* Email address */
};

/******************************************************************************
 * ROTATE KERNEL
 *****************************************************************************/

// Your different versions of the rotate kernel go here

/*
 * naive_rotate - The naive baseline version of rotate
 */
/* stride pattern, visualization (we recommend that you draw this for your functions):
    dst         src
    3 7 B F     0 1 2 3
    2 6 A E     4 5 6 7
    1 5 9 D     8 9 A B
    0 4 8 C     C D E F
 */
char naive_rotate_descr[] = "naive_rotate: Naive baseline implementation";
void naive_rotate(int dim, pixel *src, pixel *dst)
{
    int i, j;

    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
            dst[RIDX(dim - 1 - j, i, dim)] = src[RIDX(i, j, dim)];
}

/*
 * rotate - Your current working version of rotate
 * IMPORTANT: This is the version you will be graded on
 */
char rotate_descr[] = "rotate: Current working version";
void rotate(int dim, pixel *src, pixel *dst)
{
    int i, j;

    for (i = 0; i < dim; i++)
    {
        pixel *src_addr = src + i * dim; //i*dim + j
        pixel *dst_addr = dst + ((dim - 1) * dim + i); //(dim - 1 - j)*dim + i
    
        for (j = 0; j < dim; j += 32)
        {
            int negjdim = -j*dim;
            dst_addr[negjdim] = src_addr[j];
            dst_addr[negjdim - dim] = src_addr[j+1];
            dst_addr[negjdim - (2*dim)] = src_addr[j+2];
            dst_addr[negjdim - (3*dim)] = src_addr[j+3];
            dst_addr[negjdim - (4*dim)] = src_addr[j+4];
            dst_addr[negjdim - (5*dim)] = src_addr[j+5];
            dst_addr[negjdim - (6*dim)] = src_addr[j+6];
            dst_addr[negjdim - (7*dim)] = src_addr[j+7];
            dst_addr[negjdim - (8*dim)] = src_addr[j+8];
            dst_addr[negjdim - (9*dim)] = src_addr[j+9];
            dst_addr[negjdim - (10*dim)] = src_addr[j+10];
            dst_addr[negjdim - (11*dim)] = src_addr[j+11];
            dst_addr[negjdim - (12*dim)] = src_addr[j+12];
            dst_addr[negjdim - (13*dim)] = src_addr[j+13];
            dst_addr[negjdim - (14*dim)] = src_addr[j+14];
            dst_addr[negjdim - (15*dim)] = src_addr[j+15];
            dst_addr[negjdim - (16*dim)] = src_addr[j+16];
            dst_addr[negjdim - (17*dim)] = src_addr[j+17];
            dst_addr[negjdim - (18*dim)] = src_addr[j+18];
            dst_addr[negjdim - (19*dim)] = src_addr[j+19];
            dst_addr[negjdim - (20*dim)] = src_addr[j+20];
            dst_addr[negjdim - (21*dim)] = src_addr[j+21];
            dst_addr[negjdim - (22*dim)] = src_addr[j+22];
            dst_addr[negjdim - (23*dim)] = src_addr[j+23];
            dst_addr[negjdim - (24*dim)] = src_addr[j+24];
            dst_addr[negjdim - (25*dim)] = src_addr[j+25];
            dst_addr[negjdim - (26*dim)] = src_addr[j+26];
            dst_addr[negjdim - (27*dim)] = src_addr[j+27];
            dst_addr[negjdim - (28*dim)] = src_addr[j+28];
            dst_addr[negjdim - (29*dim)] = src_addr[j+29];
            dst_addr[negjdim - (30*dim)] = src_addr[j+30];
            dst_addr[negjdim - (31*dim)] = src_addr[j+31];
        }
    }
}

/*
 * register_rotate_functions - Register all of your different versions
 *     of the rotate kernel with the driver by calling the
 *     add_rotate_function() for each test function.
 */
void register_rotate_functions()
{
    add_rotate_function(&naive_rotate, naive_rotate_descr);
    add_rotate_function(&rotate, rotate_descr);
    /* ... Register additional test functions here */
}

/******************************************************************************
 * ROTATE_T KERNEL
 *****************************************************************************/

// Your different versions of the rotate_t kernel go here
// (i.e. rotate with multi-threading)

/*
 * rotate_t - Your current working version of rotate_t
 * IMPORTANT: This is the version you will be graded on
 */
char rotate_t_descr[] = "rotate_t: Current working version";
void rotate_t(int dim, pixel *src, pixel *dst)
{
    naive_rotate(dim, src, dst);
}

/*********************************************************************
 * register_rotate_t_functions - Register all of your different versions
 *     of the rotate_t kernel with the driver by calling the
 *     add_rotate_t_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.
 *********************************************************************/

void register_rotate_t_functions()
{
    add_rotate_t_function(&rotate_t, rotate_t_descr);
    /* ... Register additional test functions here */
}

/******************************************************************************
 * BLEND KERNEL
 *****************************************************************************/

// Your different versions of the blend kernel go here.

char naive_blend_descr[] = "naive_blend: Naive baseline implementation";
void naive_blend(int dim, pixel *src, pixel *dst) // reads global variable `pixel bgc` !
{
    int i, j;

    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
            blend_pixel(&src[RIDX(i, j, dim)], &dst[RIDX(i, j, dim)], bgc); // `blend_pixel` defined in blend.c
}

char blend_descr[] = "blend: Current working version";
void blend(int dim, pixel *src, pixel *dst)
{
    naive_blend(dim, src, dst);
}

/*
 * register_blend_functions - Register all of your different versions
 *     of the blend kernel with the driver by calling the
 *     add_blend_function() for each test function.
 */
void register_blend_functions()
{
    add_blend_function(&blend, blend_descr);
    /* ... Register additional test functions here */
}

/******************************************************************************
 * BLEND_V KERNEL
 *****************************************************************************/

// Your different versions of the blend_v kernel go here
// (i.e. with vectorization, aka. SIMD).

char blend_v_descr[] = "blend_v: Current working version";
void blend_v(int dim, pixel *src, pixel *dst)
{
    naive_blend(dim, src, dst);
}

/*
 * register_blend_v_functions - Register all of your different versions
 *     of the blend_v kernel with the driver by calling the
 *     add_blend_function() for each test function.
 */
void register_blend_v_functions()
{
    add_blend_v_function(&blend_v, blend_v_descr);
    /* ... Register additional test functions here */
}

/******************************************************************************
 * SMOOTH KERNEL
 *****************************************************************************/

// Your different versions of the smooth kernel go here

/*
 * naive_smooth - The naive baseline version of smooth
 */
char naive_smooth_descr[] = "naive_smooth: Naive baseline implementation";
void naive_smooth(int dim, pixel *src, pixel *dst)
{
    int i, j;

    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
            dst[RIDX(i, j, dim)] = avg(dim, i, j, src); // `avg` defined in smooth.c
}

char smooth_descr[] = "smooth: Current working version";
void smooth(int dim, pixel *src, pixel *dst)
{
    naive_smooth(dim, src, dst);
}

/*
 * register_smooth_functions - Register all of your different versions
 *     of the smooth kernel with the driver by calling the
 *     add_smooth_function() for each test function.
 */

void register_smooth_functions()
{
    add_smooth_function(&naive_smooth, naive_smooth_descr);
    /* ... Register additional test functions here */
}
