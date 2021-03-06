#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit NECK;

#include "message.h"

void create()
{
  set_name(HIY"二胡"NOR, ({ "er hu"}));
  set_weight(800);
  set("material", "wood");
  set("long","一把古旧的二胡。\n");
  set("unit", "把");
  set("armor_prop/armor", 1);
  set("armor_prop/personality", 1);
  setup();
}

int init ()
{
  add_action ("do_wear", "wear");
  add_action ("do_remove", "remove");
  add_action ("do_play", "play");
  add_action ("do_play", "la");
  return 1;
}

int do_wear (string arg)
{
  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "er hu")
    return 0;
  msg = "$N拉起"+name+",凄厉的乐声如鬼神齐嚎,令人心惊。\n"; 
  flower->set("wear_msg",msg);
  return 0;
}

int do_remove (string arg)
{
  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "er hu")
    return 0;

  msg = "$N长叹一声,将"+name+"轻轻地收起来……\n"; 
  flower->set("unequip_msg",msg);
  return 0;
}

int do_play (string arg)
{
  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "er hu")
    return 0;

  msg = "$N拉起"+name+",乐声凄厉,催人泪下。\n"; 
  message_vision (msg,me);
  return 1;
}
