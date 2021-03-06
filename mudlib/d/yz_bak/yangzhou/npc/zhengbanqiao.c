// Mr.music  yangzhou' 郑板桥

inherit NPC;

void create()
{
	set_name("郑板桥", ({ "zhengbanqiao","zheng", "banqiao" }));
	set("long", "扬州八怪之首，当代书画奇才。\n");
	set("gender", "男性");
	set("age", 35);
        set("per", 10);
        set("class","shusheng");
        set("mingwang",1);
	set_skill("literate", 200);

         create_family("扬州八怪", 1, "大哥大");

        set("title","维扬怪杰");
	set_skill("unarmed", 80);
        set_skill("force",150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
        set_skill("sword",100);
        set_skill("throwing",100);
        set_skill("qiankunyizhi",120);

        map_skill("throwing","qiankunyizhi");
	map_skill("parry","qiankunyizhi");
	set_temp("apply/attack", 90);
	set_temp("apply/defense", 90);
	set_temp("apply/damage", 50);

	set("combat_exp", 900000);
	set("shen_type", 1);

	setup();

	set("chat_chance", 1);
	set("chat_msg", ({
	       	"郑板桥看了你一眼，赞许的点点头。\n",
                "郑板桥对你笑笑，说：我们只是些文人，谈不上门派。\n",
                "郑板桥若有所思的看着池水，不知想些啥。\n",
                	}) );

        carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"obj/zhuye")->wield();
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/郑"))
		return 0; 
	ob->add_temp("mark/郑", -1);
	return 1;
}

int accept_object(object who, object ob)
{
	if (!(int)who->query_temp("mark/郑"))
		who->set_temp("mark/郑", 0);
	if (ob->query("money_id") && ob->value() >= 500) {
		message_vision("郑板桥揽了下长须，向$N点了点头。\n", who);
		who->add_temp("mark/郑", ob->value() / 30);
		return 1;
	}
	return 0;
}



void attempt_apprentice(object ob)
 {
        if( ((int)ob->query("int") < 15)) 
            {
                command("say " + RANK_D->query_respect(ob) +
"你的悟性好象不够 .....\n");
             return ;
            }
        command("say " + RANK_D->query_respect(ob) +
 "聪明伶俐，日后必成大器。\n");
        command("recruit " + ob->query("id") );
 }


 void recruit_apprentice(object ob)
 {
        if( ::recruit_apprentice(ob) )
                ob->set("class", "shusheng");
 }


