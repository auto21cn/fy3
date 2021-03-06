inherit NPC;

void create()
{
   set_name("未羊", ({ "sheep","yang" }) );
   set("race", "野兽");
   set("age", 22);
   set("long", "白色的羊毛卷曲,温柔的眼波,千万不要被外表迷糊。\n");
   
   set("str", 13);
   set("cor", 24);
   set("combat_exp",55000);
   set("kee",600);
   set("max_kee",600);

   set("limbs", ({ "头部", "身体", "尾巴", "前蹄","后蹄" "羊角"}) );
   set("verbs", ({ "bite", "claw" }) );

   set_temp("apply/attack", 15);
   set_temp("apply/armor", 20);
   
   set("chat_chance",5);
   set("chat_msg",({
     "未羊摇头晃脑一阵,似乎吟出了一首好诗而得意.\n",
     "未羊摆摆蹄子,动动腿,低头向你撞来.\n",
     }));

   setup();
}

void die()
{
  message_vision("$N仰天长叹:天亡我也.倒地死去.\n",this_object());
  new(__DIR__"obj/yangrou.c")->move(environment(this_object()));
  destruct(this_object());
  return;
}