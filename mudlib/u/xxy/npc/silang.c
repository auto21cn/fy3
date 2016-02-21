#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
void create()
{
     set_name("吴四郎",({"wu silang","silang"}));
     set("shen_type",1);
     set("gender","男性");
     set("age",22);
     set("str",19);
     set_skill("unarmed",30);
     set_skill("parry",30);
     set_skill("dodge",30);
     set("combat_exp",6000);
     set("chat_chance",5);
     set("chat_msg",({
              HIG+"----草鞋---新编的草鞋---，谁要买草鞋?\n"+NOR,
              HIG+"吴四郎自言自语：‘看来今天的草鞋又卖不完了.'\n"+NOR,
              (:random_move:),
                 }));
      set("vendor_goods",([
                    "caoxie":__DIR__"obj/caoxie",
                 ]));
    setup();
    carry_object("/obj/cloth")->wear();
    add_money("coin",100);
}
void init()
{
    add_action("do_vendor_list","list");
}
           
             