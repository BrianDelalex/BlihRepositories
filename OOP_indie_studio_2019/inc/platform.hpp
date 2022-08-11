#ifndef PLATFORM_HPP_
#define PLATFORM_HPP_

# if defined(_WIN32)
    # define PLATFORM_NAME "windows" // Windows
# elif defined(_WIN64)
    # define PLATFORM_NAME "windows" // Windows
# elif defined(__CYGWIN__) && !defined(_WIN32)
    # define PLATFORM_NAME "windows"
# elif defined(__linux__)
    # define PLATFORM_NAME "linux" // Debian, Ubuntu, Gentoo, Fedora, openSUSE, RedHat, Centos and othe
#endif

#endif