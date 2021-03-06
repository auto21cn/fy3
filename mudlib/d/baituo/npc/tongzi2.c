inherit NPC;
int do_bi(string arg);
void greeting(object);
void init();
void create()
{
        set_name("陪练童子", ({ "tongzi"}) );
        set("gender", "男性" );
        set("age", 16);
        set("long", "这是个陪人练功的陪练童子。\n");
        set("attitude", "friendly");
        set("shen_type", -1);

        set("str", 21);
        set("int", 21);
        set("con", 21);
        set("dex", 20);

        set("max_kee", 200);
        set("combat_exp", 10000);
        set("score", 500);
        set_skill("force", 20);
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_skill("parry",20);
        create_family("白驼山派",10,"弟子");
        set("chat_chance", 2);
        set("chat_msg", ({
                "陪练童子说道: 听说我们白驼山的镇山之宝是江湖上人人都想得到的神杖!\n",
        }) );
        set("inquiry", ([
                "镇山之宝"       :"我们白驼山有一根神杖是镇山之宝!\n",
                "神杖"          :"那跟神杖好象叫天魔杖！\n",
        ]) );


        setup();
}

void init()
{
        object ob;
        add_action("do_bi","bi");


        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if (((string)ob->query("family/family_name") == "白驼山派")
            &&ob->query("combat_exp")<10000)
         message_vision("陪练童子冲着$N叫道：快来跟我比划几招。(bi tongzi)\n",ob);
}

void attempt_apprentice(object ob)
{
     command("say 我不能收徒。你还是拜李教头吧。\n");
     return;
}

int do_bi(string arg)
{
  object ob=this_player();
  if(!arg||arg!="tongzi") return  notify_fail("你要和谁比划?\n");
  if ((int)ob->query("combat_exp")>10000)
   return notify_fail("陪练童子摇头道：以你的武功,我不能做你的陪练了。\n");
  say("陪练童子同意作你的陪练。\n");
  set("combat_exp",ob->query("combat_exp"));
  command("hit "+(string)ob->query("id"));
  if(query("kee")<40)
    message_vision("陪练童子对$N大加赞赏!\n",ob);
  else
    message_vision("陪练童子对$N笑笑道：努力吧。\n",ob);

  set("eff_kee",200);
  set("kee",200);
  set("combat_exp",10000);
  return 1;
}

int accept_fight(object ob)
{
      if ((string)ob->query("family/family_name") == "白驼山派")
         {
          if((int)ob->query("combat_exp")<5000)
            return notify_fail("陪练童子笑道：你的经验太低了，还是先到比划吧！(bi tongzi)\n");
          }
    message_vision("陪练童子对$N叫道：那我就不让你了！\n",ob);
    return 1;
}

