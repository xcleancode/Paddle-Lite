// Copyright (c) 2023 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#if defined(__APPLE__)
#include <TargetConditionals.h>
#endif

#if defined(__i386__) || defined(__i486__) || defined(__i586__) || \
    defined(__i686__) || defined(_M_IX86)
#define ADNN_ARCH_X86 1
#else
#define ADNN_ARCH_X86 0
#endif

#if defined(__x86_64__) || defined(__x86_64) || \
    defined(_M_X64) && !defined(_M_ARM64EC)
#define ADNN_ARCH_X86_64 1
#else
#define ADNN_ARCH_X86_64 0
#endif

#if defined(__arm__) || defined(_M_ARM)
#define ADNN_ARCH_ARM 1
#else
#define ADNN_ARCH_ARM 0
#endif

#if defined(__aarch64__) || defined(_M_ARM64) || defined(_M_ARM64EC)
#define ADNN_ARCH_ARM64 1
#else
#define ADNN_ARCH_ARM64 0
#endif

#if defined(__ANDROID__)
#define ADNN_OS_ANDROID 1
#else
#define ADNN_OS_ANDROID 0
#endif

#if defined(__linux__)
#define ADNN_OS_LINUX 1
#else
#define ADNN_OS_LINUX 0
#endif

#if defined(__APPLE__) && TARGET_OS_IPHONE
#define ADNN_OS_IOS 1
#else
#define ADNN_OS_IOS 0
#endif

#if defined(__APPLE__) && TARGET_OS_MAC
#define ADNN_OS_MAC 1
#else
#define ADNN_OS_MAC 0
#endif

#if defined(_WIN32)
#define ADNN_OS_WINDOWS 1
#else
#define ADNN_OS_WINDOWS 0
#endif

#if defined(__QNX__)
#define ADNN_OS_QNX 1
#else
#define ADNN_OS_QNX 0
#endif

#if defined(__clang__)
#define ADNN_COMPILER_CLANG 1
#elif defined(_MSC_VER)
#define ADNN_COMPILER_MSVC 1
#elif defined(__GNUC__)
#define ADNN_COMPILER_GCC 1
#endif

#ifndef ADNN_COMPILER_CLANG
#define ADNN_COMPILER_CLANG 0
#endif

#ifndef ADNN_COMPILER_MSVC
#define ADNN_COMPILER_MSVC 0
#endif

#ifndef ADNN_COMPILER_GCC
#define ADNN_COMPILER_GCC 0
#endif

#ifndef ADNN_DISALLOW_COPY_AND_ASSIGN
#define ADNN_DISALLOW_COPY_AND_ASSIGN(class__) \
  class__(const class__&) = delete;            \
  class__& operator=(const class__&) = delete;
#endif

#if !defined(_WIN32)
#define ADNN_ALIGN(x) __attribute__((aligned(x)))
#else
#define ADNN_ALIGN(x) __declspec(align(x))
#endif

#if defined _WIN32 || defined __CYGWIN__
#define ADNN_DLL_EXPORT __declspec(dllexport)
#define ADNN_DLL_IMPORT __declspec(dllimport)
#else
#if __GNUC__ >= 4
#define ADNN_DLL_EXPORT __attribute__((visibility("default")))
#define ADNN_DLL_IMPORT __attribute__((visibility("default")))
#else
#define ADNN_DLL_EXPORT
#define ADNN_DLL_IMPORT
#endif
#endif

#if (defined __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__) && \
    (__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__ < 90000)
// Thread local storage is not supported by iOS8 or before.
#define ADNN_THREAD_LOCAL
#elif defined(__cplusplus) && (__cplusplus >= 201103)
#define ADNN_THREAD_LOCAL thread_local
#elif ADNN_OS_WINDOWS
// thread_local is not supported by MSVC.
#define ADNN_THREAD_LOCAL thread_local
#else
#error "C++11 support is required for thread_local."
#endif
