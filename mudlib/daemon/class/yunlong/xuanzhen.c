// xuanzhen.c 

#include <ansi.h>
inherit NPC;

string ask_me();
void create()
{
	set_name("玄真道长", ({ "xuan zhen", "xuan", "zhen" }));
	set("gender", "男性");
	set("long", "\n这位沉默寡言的道人，便是天地会青木堂护法。\n"+
		"他是青木堂数一数二的好手，一柄长剑使得出神入化。\n");
	set("age", 55);
	set("banghui","天地会");
	set("bh_rank","青木堂护法");

	set("int", 30);
	
	set("kee", 2000);
	set("max_kee", 2000);
	set("gin", 500);
	set("max_gin", 500);
	set("mingwang",600);
	set("max_force",1500);
	set("force",1500);
	set("force_factor",100);

	set("combat_exp", 1000000);
	set("attitude", "friendly");

	set_skill("force", 150);
	set_skill("unarmed", 150);
	set_skill("parry", 150);
	set_skill("dodge", 150);
	set_skill("sword", 150);
	set_skill("whip", 150);

	set_skill("yunlong-shenfa", 150);
	set_skill("yunlong-xinfa", 150);
	set_skill("yunlong-shou", 150);
	set_skill("yunlong-jianfa",150);
	set_skill("yunlong-bianfa",150);
	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/damage", 60);

	map_skill("force", "yunlong-xinfa");
	map_skill("dodge", "yunlong-shenfa");
	map_skill("parry", "yunlong-jianfa");
	map_skill("sword", "yunlong-jianfa");
	map_skill("unarmed", "yunlong-shou");
	map_skill("whip", "yunlong-bian");

	set("book_count", 1);
        set("inquiry", ([
		"陈近南" :  "\n总舵主就在里面。\n",
		"天地会" :  "\n只要是英雄好汉，都可以入我天地会。\n",
		"云龙经" : (: ask_me :),
       ]) );
	set("chat_chance_combat", 50);  
	set("chat_msg_combat", ({
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield bian") :),
		(: command("wield bian") :),
		(: command("wield bian") :),
		(: command("wield bian") :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "sword.xian" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "whip.chan" :),
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
		(: command("unwield bian") :),
		(: command("unwield bian") :),
		(: command("unwield bian") :),
		(: command("unwield bian") :),
                      }) );
	setup();
	carry_object("/obj/weapon/sword")->wield();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/weapon/whip")->wield();
        add_money("gold",3);
}

void init()
{
        object ob;

        ::init();

        if( interactive(ob=this_player()) && !is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting",1,ob);
        }
}

string ask_me()
{
        string banghui; 
	object ob;

	banghui=(string)this_player()->query("banghui");
	if(! banghui || banghui!=(string)query("banghui"))
                return RANK_D->query_respect(this_player()) + 
                "与我天地会素无来往，不知此话从何谈起？";
        if (query("book_count") < 1)
                return "你来晚了，云龙真经不在此处。";
        add("book_count", -1);
        ob = new("/d/huanggon/obj/yljing2");
        ob->move(this_player());
        return "好吧，这本「云龙经」你拿回去好好钻研。";
}

void greeting(object ob)
{
	string banghui;
	banghui=(string)ob->query("banghui");

	if( !ob || environment(ob) != environment() ) return;
	if(banghui==(string)query("banghui"))	{
			say( "玄真道：这位" + RANK_D->query_respect(ob)
				+ "，总舵主正在香堂等你，快些去吧。\n");
	}
	else if((int)ob->query("mingwang")<-10000)	{
		say("玄真喝道：你这个武林败类，纳命来吧！\n");
		kill_ob(ob);
		ob->fight_ob(this_object());
	}
	else say( "玄真笑道：这位" + RANK_D->query_respect(ob)
				+ "，到这儿来干什么？\n");
 
}


int recognize_apprentice(object ob)
{
        string banghui;
        if(! stringp(banghui=ob->query("banghui")) ||
                banghui!=query("banghui"))
        return notify_fail(query("name")+"摇头道：非我天地会兄弟不教。\n");
	if(ob->query("score")<2500)
                return notify_fail(query("name")+"道：你要多为天地会出力啊。\n")
;
        return 1;
}
