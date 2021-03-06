﻿/***********************************************************************************
**
** GUIGroup.h
**
** Компонента группы
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/
//----------------------------------------------------------------------------------
#ifndef GUIGROUP_H
#define GUIGROUP_H
//----------------------------------------------------------------------------------
class CGUIGroup : public CBaseGUI
{
public:
    //!Индекс группы. 0 - эквивалентно EndGroup
    int Index = 0;

    CGUIGroup(int index);
    virtual ~CGUIGroup();
};
//----------------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------------
