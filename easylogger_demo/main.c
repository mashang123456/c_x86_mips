/*
 * This file is part of the EasyLogger Library.
 *
 * Copyright (c) 2015-2017, Armink, <armink.ztl@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * 'Software'), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Function: linux demo.
 * Created on: 2015-07-30
 */

//#define LOG_TAG    "main"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "elog.h"

void test()
{
    int i = 5;
    char buf[10] = "happy";
    log_i("test info:[%d][%s]", i, buf);
}


int main(void) 
{
    setbuf(stdout, NULL);   //close printf buffer

    elog_init();	//initialize EasyLogger

    //分别设置6个log级别打印格式ELOG_FMT_LVL|ELOG_FMT_TAG|ELOG_FMT_TIME|ELOG_FMT_P_INFO|ELOG_FMT_T_INFO|ELOG_FMT_DIR|ELOG_FMT_FUNC|ELOG_FMT_LINE
    elog_set_fmt(ELOG_LVL_ASSERT, ELOG_FMT_ALL);
    elog_set_fmt(ELOG_LVL_ERROR, ELOG_FMT_ALL);
    elog_set_fmt(ELOG_LVL_WARN, ELOG_FMT_ALL & ~ELOG_FMT_LVL & ~ELOG_FMT_TAG);
    elog_set_fmt(ELOG_LVL_INFO, ELOG_FMT_TIME | ELOG_FMT_T_INFO | ELOG_FMT_DIR |ELOG_FMT_FUNC | ELOG_FMT_LINE);
    elog_set_fmt(ELOG_LVL_DEBUG, ELOG_FMT_ALL & ~ELOG_FMT_LVL & ~ELOG_FMT_TAG & ~ELOG_FMT_P_INFO);
    elog_set_fmt(ELOG_LVL_VERBOSE, ELOG_FMT_ALL & ~ELOG_FMT_FUNC);

    elog_start();  //start EasyLogger 

    while(true) 
    {
        /* test log output for all level */
        log_a("Hello EasyLogger!assert\n");
        log_e("Hello EasyLogger!error\n");
        log_w("Hello EasyLogger!warn\n");
        log_i("Hello EasyLogger!info\n");
        log_d("Hello EasyLogger!debug\n");
        log_v("Hello EasyLogger!verbose\n");
        //elog_raw("Hello EasyLogger!raw\n");
        test();
        //elog_hexdump("test", 16, buf, sizeof(buf));
        sleep(5);
    }

    return EXIT_SUCCESS;
}



