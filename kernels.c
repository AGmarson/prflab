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


char rotate_32_descr[] = "rotate_32: loop unroll 32, blocksize 32";
void rotate_32(int dim, pixel *src, pixel *dst)
{
    int i, blocksize, bi, bj;
    blocksize = 32;
    for (bi = 0; bi < dim; bi += blocksize)
    {
        for (bj = 0; bj < dim; bj += blocksize)
        {
            for (i = bi; i < bi + blocksize; i++)
            {
                pixel *src_addr = src + RIDX(i, bj, dim);             // i*dim + bj
                pixel *dst_addr = dst + RIDX((dim - 1 - bj), i, dim); //(dim - 1 - bj)*dim + i
                dst_addr[0] = src_addr[0];
                dst_addr[-dim] = src_addr[1];
                dst_addr[-(2 * dim)] = src_addr[2];
                dst_addr[-(3 * dim)] = src_addr[3];
                dst_addr[-(4 * dim)] = src_addr[4];
                dst_addr[-(5 * dim)] = src_addr[5];
                dst_addr[-(6 * dim)] = src_addr[6];
                dst_addr[-(7 * dim)] = src_addr[7];
                dst_addr[-(8 * dim)] = src_addr[8];
                dst_addr[-(9 * dim)] = src_addr[9];
                dst_addr[-(10 * dim)] = src_addr[10];
                dst_addr[-(11 * dim)] = src_addr[11];
                dst_addr[-(12 * dim)] = src_addr[12];
                dst_addr[-(13 * dim)] = src_addr[13];
                dst_addr[-(14 * dim)] = src_addr[14];
                dst_addr[-(15 * dim)] = src_addr[15];
                dst_addr[-(16 * dim)] = src_addr[16];
                dst_addr[-(17 * dim)] = src_addr[17];
                dst_addr[-(18 * dim)] = src_addr[18];
                dst_addr[-(19 * dim)] = src_addr[19];
                dst_addr[-(20 * dim)] = src_addr[20];
                dst_addr[-(21 * dim)] = src_addr[21];
                dst_addr[-(22 * dim)] = src_addr[22];
                dst_addr[-(23 * dim)] = src_addr[23];
                dst_addr[-(24 * dim)] = src_addr[24];
                dst_addr[-(25 * dim)] = src_addr[25];
                dst_addr[-(26 * dim)] = src_addr[26];
                dst_addr[-(27 * dim)] = src_addr[27];
                dst_addr[-(28 * dim)] = src_addr[28];
                dst_addr[-(29 * dim)] = src_addr[29];
                dst_addr[-(30 * dim)] = src_addr[30];
                dst_addr[-(31 * dim)] = src_addr[31];
            }
        }
    }
}

char rotate_16_descr[] = "rotate_8: loop unroll 16, blocksize 16";
void rotate_16(int dim, pixel *src, pixel *dst)
{
    int i, blocksize, bi, bj;
    blocksize = 16;
    for (bi = 0; bi < dim; bi += blocksize)
    {
        for (bj = 0; bj < dim; bj += blocksize)
        {
            for (i = bi; i < bi + blocksize; i++)
            {
                pixel *src_addr = src + RIDX(i, bj, dim);             // i*dim + bj
                pixel *dst_addr = dst + RIDX((dim - 1 - bj), i, dim); //(dim - 1 - bj)*dim + i
                dst_addr[0] = src_addr[0];
                dst_addr[-dim] = src_addr[1];
                dst_addr[-(2 * dim)] = src_addr[2];
                dst_addr[-(3 * dim)] = src_addr[3];
                dst_addr[-(4 * dim)] = src_addr[4];
                dst_addr[-(5 * dim)] = src_addr[5];
                dst_addr[-(6 * dim)] = src_addr[6];
                dst_addr[-(7 * dim)] = src_addr[7];
                dst_addr[-(8 * dim)] = src_addr[8];
                dst_addr[-(9 * dim)] = src_addr[9];
                dst_addr[-(10 * dim)] = src_addr[10];
                dst_addr[-(11 * dim)] = src_addr[11];
                dst_addr[-(12 * dim)] = src_addr[12];
                dst_addr[-(13 * dim)] = src_addr[13];
                dst_addr[-(14 * dim)] = src_addr[14];
                dst_addr[-(15 * dim)] = src_addr[15];
            }
        }
    }
}

char rotate_8_descr[] = "rotate_8: loop unroll 8, blocksize 8";
void rotate_8(int dim, pixel *src, pixel *dst)
{
    int i, blocksize, bi, bj;
    blocksize = 8;
    for (bi = 0; bi < dim; bi += blocksize)
    {
        for (bj = 0; bj < dim; bj += blocksize)
        {
            for (i = bi; i < bi + blocksize; i++)
            {
                pixel *src_addr = src + RIDX(i, bj, dim);             // i*dim + bj
                pixel *dst_addr = dst + RIDX((dim - 1 - bj), i, dim); //(dim - 1 - bj)*dim + i
                dst_addr[0] = src_addr[0];
                dst_addr[-dim] = src_addr[1];
                dst_addr[-(2 * dim)] = src_addr[2];
                dst_addr[-(3 * dim)] = src_addr[3];
                dst_addr[-(4 * dim)] = src_addr[4];
                dst_addr[-(5 * dim)] = src_addr[5];
                dst_addr[-(6 * dim)] = src_addr[6];
                dst_addr[-(7 * dim)] = src_addr[7];
            }
        }
    }
}

char rotate_4_descr[] = "rotate_4: loop unroll 4, blocksize 4";
void rotate_4(int dim, pixel *src, pixel *dst)
{
    int i, blocksize, bi, bj;
    blocksize = 4;
    for (bi = 0; bi < dim; bi += blocksize)
    {
        for (bj = 0; bj < dim; bj += blocksize)
        {
            for (i = bi; i < bi + blocksize; i++)
            {
                pixel *src_addr = src + RIDX(i, bj, dim);             // i*dim + bj
                pixel *dst_addr = dst + RIDX((dim - 1 - bj), i, dim); //(dim - 1 - bj)*dim + i
                dst_addr[0] = src_addr[0];
                dst_addr[-dim] = src_addr[1];
                dst_addr[-(2 * dim)] = src_addr[2];
                dst_addr[-(3 * dim)] = src_addr[3];
            }
        }
    }
}

/*
 * rotate - Your current working version of rotate
 * IMPORTANT: This is the version you will be graded on
 */
char rotate_descr[] = "rotate: current best working solution";
void rotate(int dim, pixel *src, pixel *dst)
{
    rotate_8(dim, src, dst);
}

/*
 * register_rotate_functions - Register all of your different versions
 *     of the rotate kernel with the driver by calling the
 *     add_rotate_function() for each test function.
 */
void register_rotate_functions()
{
    add_rotate_function(&naive_rotate, naive_rotate_descr);
    add_rotate_function(&rotate_32, rotate_32_descr);
    add_rotate_function(&rotate_16, rotate_16_descr);
    add_rotate_function(&rotate_8, rotate_8_descr);
    add_rotate_function(&rotate_4, rotate_4_descr);
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

typedef vec_t __attribute__ ((pixel));

char naive_blend_descr[] = "naive_blend: Naive baseline implementation";
void naive_blend(int dim, pixel *src, pixel *dst) // reads global variable `pixel bgc` !
{
    int i, j;

    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
            blend_pixel(&src[RIDX(i, j, dim)], &dst[RIDX(i, j, dim)], bgc); // `blend_pixel` defined in blend.c
}

char blend_32_descr[] = "blend: loop unroll 32";
void blend_32(int dim, pixel *src, pixel *dst)
{
    int i, j;

    for (i = 0; i < dim; i++)
    {
        pixel *src_addr = src + i * dim; //i*dim + j
        pixel *dst_addr = dst + i * dim;
        for (j = 0; j < dim; j += 32)
        {
            blend_pixel(&src_addr[0], &dst_addr[0], bgc);
            blend_pixel(&src_addr[1], &dst_addr[1], bgc);
            blend_pixel(&src_addr[2], &dst_addr[2], bgc);
            blend_pixel(&src_addr[3], &dst_addr[3], bgc);
            blend_pixel(&src_addr[4], &dst_addr[4], bgc);
            blend_pixel(&src_addr[5], &dst_addr[5], bgc);
            blend_pixel(&src_addr[6], &dst_addr[6], bgc);
            blend_pixel(&src_addr[7], &dst_addr[7], bgc);
            blend_pixel(&src_addr[8], &dst_addr[8], bgc);
            blend_pixel(&src_addr[9], &dst_addr[9], bgc);
            blend_pixel(&src_addr[10], &dst_addr[10], bgc);
            blend_pixel(&src_addr[11], &dst_addr[11], bgc);
            blend_pixel(&src_addr[12], &dst_addr[12], bgc);
            blend_pixel(&src_addr[13], &dst_addr[13], bgc);
            blend_pixel(&src_addr[14], &dst_addr[14], bgc);
            blend_pixel(&src_addr[15], &dst_addr[15], bgc);
            blend_pixel(&src_addr[16], &dst_addr[16], bgc);
            blend_pixel(&src_addr[17], &dst_addr[17], bgc);
            blend_pixel(&src_addr[18], &dst_addr[18], bgc);
            blend_pixel(&src_addr[19], &dst_addr[19], bgc);
            blend_pixel(&src_addr[20], &dst_addr[20], bgc);
            blend_pixel(&src_addr[21], &dst_addr[21], bgc);
            blend_pixel(&src_addr[22], &dst_addr[22], bgc);
            blend_pixel(&src_addr[23], &dst_addr[23], bgc);
            blend_pixel(&src_addr[24], &dst_addr[24], bgc);
            blend_pixel(&src_addr[25], &dst_addr[25], bgc);
            blend_pixel(&src_addr[26], &dst_addr[26], bgc);
            blend_pixel(&src_addr[27], &dst_addr[27], bgc);
            blend_pixel(&src_addr[28], &dst_addr[28], bgc);
            blend_pixel(&src_addr[29], &dst_addr[29], bgc);
            blend_pixel(&src_addr[30], &dst_addr[30], bgc);
            blend_pixel(&src_addr[31], &dst_addr[31], bgc);
            src_addr += 32;
            dst_addr += 32;
        }
    }
}

char blend_16_descr[] = "blend: loop unroll 16 and ++";
void blend_16(int dim, pixel *src, pixel *dst)
{
    int i, j;

    for (i = 0; i < dim; i++)
    {
        pixel *src_addr = src + i * dim; //i*dim + j
        pixel *dst_addr = dst + i * dim;
        for (j = 0; j < dim; j += 16)
        {
            blend_pixel(src_addr++, dst_addr++, bgc);
            blend_pixel(src_addr++, dst_addr++, bgc);
            blend_pixel(src_addr++, dst_addr++, bgc);
            blend_pixel(src_addr++, dst_addr++, bgc);
            blend_pixel(src_addr++, dst_addr++, bgc);
            blend_pixel(src_addr++, dst_addr++, bgc);
            blend_pixel(src_addr++, dst_addr++, bgc);
            blend_pixel(src_addr++, dst_addr++, bgc);
            blend_pixel(src_addr++, dst_addr++, bgc);
            blend_pixel(src_addr++, dst_addr++, bgc);
            blend_pixel(src_addr++, dst_addr++, bgc);
            blend_pixel(src_addr++, dst_addr++, bgc);
            blend_pixel(src_addr++, dst_addr++, bgc);
            blend_pixel(src_addr++, dst_addr++, bgc);
            blend_pixel(src_addr++, dst_addr++, bgc);
            blend_pixel(src_addr++, dst_addr++, bgc);
        }
    }
}

char blend_descr[] = "blend: Current working version";
void blend(int dim, pixel *src, pixel *dst)
{
    blend_32(dim, src, dst);
}

/*
 * register_blend_functions - Register all of your different versions
 *     of the blend kernel with the driver by calling the
 *     add_blend_function() for each test function.
 */
void register_blend_functions()
{
    add_blend_function(&blend_32, blend_32_descr);
    add_blend_function(&blend_16, blend_16_descr);
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
