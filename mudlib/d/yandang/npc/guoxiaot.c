inherit NPC;

void create()
{
	set_name("��Х��", ({ "guo xiaotian","guo", "dizi" }));
	set("age", 32);
	set("gender", "����");
	set("attitude", "peaceful");
	set("str", 34);
set("nickname","ɽׯ�ܼ�");
	set("combat_exp", 20000+random(10000));
	set_skill("unarmed", 60+random(40));
	set_skill("dodge", 60+random(40));
	set_skill("parry", 60+random(40));
	set_skill("sword", 60+random(40));
	set_skill("force", 60+random(40));
set_skill("luoyan-jianfa", 40+random(40));
set_skill("yuxuan-guizhen", 60+random(40));
	set_skill("tianfeng-xuan", 40+random(40));
	set_skill("tiangang-zhi", 40+random(40));
map_skill("force", "yuxuan-guizhen");
       map_skill("dodge","tianfeng-xuan");
map_skill("sword","luoyan-jianfa");
       map_skill("parry","tiangang-zhi");
       map_skill("unarmed","tiangang-zhi");
        set("shen_type",1);
	setup();
       add_money("silver",60);
	carry_object("obj/weapon/sword")->wield();
	carry_object("obj/cloth")->wear();
}
void init()
{      object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");

                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
  if( !ob || environment(ob) != environment() ) return;
     if(ob->query("family/family_name")=="�㵴��" ) 
    {  if (ob->query("combat_exp")<1000)
      { message_vision("��Х����ϸ��������һ�۵�����λ"+
        RANK_D->query_respect(ob)+",����ȥ������������!\n",ob);
        ob->set_temp("agree",1);}
       else 
       { if (ob->query("combat_exp")<3000)
            {  message_vision("��Х����ϸ��������һ�۵�����λ"+
            RANK_D->query_respect(ob)+",����ȥ������������!\n",ob);
            ob->set_temp("agree",2);}
         else 
        { message_vision("��Х����ϸ��������һ�۵�����λ"+
         RANK_D->query_respect(ob)+",����ȥ������������!\n",ob);
         ob->set_temp("agree",3);}
       }
return;
   }
return;
}