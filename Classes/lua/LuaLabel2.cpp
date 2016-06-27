/*
** Lua binding: Label
** Generated automatically by tolua++-1.0.92 on Sun Jun 26 12:07:00 2016.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_Label_open (lua_State* tolua_S);

#include "Label.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Label (lua_State* tolua_S)
{
 Label* self = (Label*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"CCPoint");
 tolua_usertype(tolua_S,"CCLabelTTF");
 tolua_usertype(tolua_S,"Label");
}

/* method: new of class  Label */
#ifndef TOLUA_DISABLE_tolua_Label_Label_new00
static int tolua_Label_Label_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Label",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Label* tolua_ret = (Label*)  Mtolua_new((Label)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Label");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Label */
#ifndef TOLUA_DISABLE_tolua_Label_Label_new00_local
static int tolua_Label_Label_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Label",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Label* tolua_ret = (Label*)  Mtolua_new((Label)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Label");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Label */
#ifndef TOLUA_DISABLE_tolua_Label_Label_delete00
static int tolua_Label_Label_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Label",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Label* self = (Label*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  Label */
#ifndef TOLUA_DISABLE_tolua_Label_Label_create00
static int tolua_Label_Label_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Label",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* label = ((const char*)  tolua_tostring(tolua_S,2,0));
  FontSize size = ((FontSize) (int)  tolua_tonumber(tolua_S,3,0));
  {
   Label* tolua_ret = (Label*)  Label::create(label,size);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Label");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPosition of class  Label */
#ifndef TOLUA_DISABLE_tolua_Label_Label_setPosition00
static int tolua_Label_Label_setPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Label",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Label* self = (Label*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint* point = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'", NULL);
#endif
  {
   self->setPosition(*point);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Label_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_constant(tolua_S,"SMALL",SMALL);
  tolua_constant(tolua_S,"MEDIUM",MEDIUM);
  tolua_constant(tolua_S,"BIG",BIG);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Label","Label","CCLabelTTF",tolua_collect_Label);
  #else
  tolua_cclass(tolua_S,"Label","Label","CCLabelTTF",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Label");
   tolua_function(tolua_S,"new",tolua_Label_Label_new00);
   tolua_function(tolua_S,"new_local",tolua_Label_Label_new00_local);
   tolua_function(tolua_S,".call",tolua_Label_Label_new00_local);
   tolua_function(tolua_S,"delete",tolua_Label_Label_delete00);
   tolua_function(tolua_S,"create",tolua_Label_Label_create00);
   tolua_function(tolua_S,"setPosition",tolua_Label_Label_setPosition00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Label (lua_State* tolua_S) {
 return tolua_Label_open(tolua_S);
};
#endif

