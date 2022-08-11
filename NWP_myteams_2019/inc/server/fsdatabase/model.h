/*
** EPITECH PROJECT, 2019
** list.h
** File description:
** list header
*/

#ifndef _DATAMODEL_H__
#define _DATAMODEL_H__

#include "def/typedef.h"
#include "server/data/users.h"
#include "server/data/channels.h"
#include "server/data/teams.h"
#include "server/data/threads.h"

#include <sys/stat.h>
#include <fcntl.h>

/*
** Database offset index definition
*/

#define FSDATABASE_INDX "fsdatabase.idx"

enum datatype_t
{
    DATA_DIRTY   = 0,
    DATA_USER    = 1,
    DATA_TEAM    = 2,
    DATA_CHANNEL = 3,
    DATA_THREAD  = 4,
    DATA_COMMENT = 5,
};

struct dataindex_t
{
    enum datatype_t type;
    int index;
};

struct rootindex
{
    struct dataindex_t dataidx;
};

/*
** Database data definition
*/

#define FSDATABASE_DATA "fsdatabase.dat"

struct teammodel_t
{
    uint teamnbr;
    uint *teamszs;
    struct team_t *teams;
};

#endif