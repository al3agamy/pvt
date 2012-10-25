/*
 +----------------------------------------------------------------------+
 |  PVT - PHP Vulnerability Tracer                                      |
 +----------------------------------------------------------------------+
 | Copyright (c) 2011  Arthur Gerkis                                    |
 +----------------------------------------------------------------------+
 | This source file is subject to version 3.01 of the PHP license,      |
 | that is bundled with this package in the file LICENSE, and is        |
 | available through the world-wide-web at the following url:           |
 | http://www.php.net/license/3_01.txt                                  |
 | If you did not receive a copy of the PHP license and are unable to   |
 | obtain it through the world-wide-web, please send a note to          |
 | license@php.net so we can mail you a copy immediately.               |
 +----------------------------------------------------------------------+
 | Author: Arthur Gerkis                                                |
 +----------------------------------------------------------------------+
*/

static char logo_b64[] =
    "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"
    "dPVxXeF60vWdm7Obwu2o26/uNu5p7ofcn8w0nymeWTNz0MPIQ+BR5dE/C5+VMGvfrH5PQ"
    "0+BZ7XnIy9jL5FXrdewt6V3qvdh7xc+9j5yn+M+4zw33jLeWV/MN8C3yLfLT8Nvnl+F30"
    "N/I/9k/3r/0QCngCUBZwOJgUGBWwL7+Hp8Ib+OPzrbZfay2e1BjKC5QRVBj4KtguXBrSF"
    "oyOyQrSH355jOkc5pDoVQfujW0Adh5mGLw34MJ4WHhVeGP45wiFga0TGXNXfR3ENz30T6"
    "RJZE3ptnMU85ry1KNSo+qi5qPNo3ujS6P8YuZlnM1VidWElsSxw5LiquNm5svt/87fOH4"
    "p3iC+N7F5gvyF1weaHOwvSFpxapLhIsOpZATIhOOJTwQRAqqBaMJfITdyWOCnnCHcJnIi"
    "/RNtGI2ENcKh5O8kgqTXqS7JG8NXkkxTOlLOW5hCepkLxMDUzdmzqeFpp2IG0yPTq9MYO"
    "SkZBxQqohTZO2Z+pn5mZ2y6xlhbL+xW6Lty8elQfJa7OQrAVZLQq2QqboVFoo1yoHsmdl"
    "V2a/zYnKOZarnivN7cyzytuQN5zvn//tEsIS4ZK2pYZLVy0dWOa9rGo5sjxxedsK4xUFK"
    "4ZWBqw8uIq2Km3VT6vtV5eufr0mek1rgV7ByoLBtQFr6wtVCuWFfevc1+1dT1gvWd+1Yf"
    "qGnRs+FYmKrhTbF5cVf9go3HjlG4dvyr+Z3JS0qavEuWTPZtJm6ebeLZ5bDpaql+aXDm4"
    "N2dq0Dd9WtO319kXbL5fNKNu7g7ZDuaO/PLi8ZafJzs07P1SkVPRU+lQ27tLdtWHX+G7R"
    "7ht7vPY07NXbW7z3/T7JvttVAVVN1WbVZftJ+7P3P66Jqun4lvttXa1ObXHtxwPSA/0HI"
    "w6217nU1R3SPVRSj9Yr60cOxx++/p3vdy0NNg1VjZzG4iNwRHnk6fcJ3/ceDTradox7rO"
    "EH0x92HWcdL2pCmvKaRptTmvtbYlu6T8w+0dbq3nr8R9sfD5w0PFl5SvNUyWna6YLTk2f"
    "yz4ydlZ19fi753GDborZ752PO32oPb++6EHTh0kX/i+c7vDvOXPK4dPKy2+UTV7hXmq86"
    "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";
