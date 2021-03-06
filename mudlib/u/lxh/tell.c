//逍遥游 1.0 BY LXH 1:49 99-1-2
// tell.c

#include <ansi.h>
#include <net/dns.h>
#include "/cmds/std/block_tell.h";
#define NEW_PERIOD 32400

inherit F_CLEAN_UP;

int help(object me);

   void create() {seteuid(getuid());}

int main(object me, string arg)
{
   string target, msg, mud;
   object obj;
   int idle;

   if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) return help(me);
//        if((int)me->query("mud_age") < NEW_PERIOD)
//                return notify_fail("你目前暂时只能使用（say）频道来交流。\n");


   if( sscanf(target, "%s@%s", target, mud)==2 ) {
     GTELL->send_gtell(mud, target, me, msg);
     write("网路讯息已送出，可能要稍候才能得到回应。\n");
     return 1;
   }

        if(!block_tell(me)) return 1;

   obj = find_player(target);
   if(!obj || !me->visible(obj)) return notify_fail("没有这个人。\n");

   if( obj->query("env/notell") && (!wizardp(me))  )
        {
         if ( stringp(obj->query("env/notell")) )
         write( GRN "自动应答告诉你："+obj->query("env/notell")+"\n" NOR );
         else write( GRN "自动应答告诉你：我正忙着呢，以后再谈。\n" NOR);
         return 1;
        }

   if( obj->query_temp("netdead") )
          return notify_fail (GRN+ obj->name(1)+"断线中...可能收不到你的信息了。\n" NOR);
        idle = query_idle(obj) /60;

   if( idle > 1 )
                write( sprintf(GRN"但是%s已经发呆超过 %d 分钟，可能不会马上回答你的话。\n"NOR,
                        gender_pronoun(obj->query("gender")),
                        idle) );    
     
   write(HIG "你告诉" + obj->name(1) + "：" + msg + "\n" NOR);
  tell_object(obj, sprintf( HIG "%s告诉你：%s\n" NOR,
     me->name(1)+"("+me->query("id")+")", msg));

   obj->set_temp("reply", me->query("id"));
   return 1;
}

string remote_tell(string cname, string from, string mud, string to, string msg)
{
   object ob;

   if( ob = find_player(to) ) {
           if(wizardp(ob) && ob->query("env/invisibility"))
       return "现在找不到这个人。"; //respond no such user.

           if( ob->query("env/block_tell") ) return
       ob->query("name")+"现在不想和任何人说话。";

                if(!living(ob) || ob->query_temp("netdead")) 
             return ob->query("name")+"现在听不见你说的话。\n";

     if( cname )
        tell_object(ob, sprintf(HIG "%s(%s@%s)告诉你：%s\n" NOR,
          cname, capitalize(from), mud, msg ));
     else
        tell_object(ob, sprintf(HIG "%s@%s 告诉你：%s\n" NOR,
          capitalize(from), mud, msg ));
     ob->set_temp("reply", from + "@" + mud);
     return ob->query("name")+"收到了你的消息。";  
     // if succeed, return target's name.
   } else
     return "现在找不到这个人。";
}

int help(object me)
{
   write(@HELP
指令格式：tell <某人> <讯息>
          tell <某人>@<Mudname> <讯息>

你可以用这个指令和其他地方的使用者说话。
也可以同其他INTERNET上的MUD游戏的玩家说话，

其他相关指令：reply, mudlist
HELP
   );
   return 1;
}


