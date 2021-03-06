// master.c

inherit NPC;
inherit F_MASTER;
int do_go();

void create()
{
	set_name("慕容复", ({ "murong fu","murong","fu"}));
	set("nickname","翩翩公子哥");
        set("gender", "男性" );
	set("max_kee",1500);
	set("age",25);
        set("str", 27);
        set("cor", 30);
        set("cps", 27);
	set("mingwang",500000);
        set("int", 24);

	set("max_force",2000);
	set("force",2000);
	set("force_factor",100);

	set("rank_info/respect","参合山庄庄主");

        set("long",
                
"南慕容的明声甚是响亮，你怎么也没想到\n"
"竟是眼前这位温文而雅的书生样的青年人。\n");

	        set("inquiry",([
	"金风庄":(:do_go:),
        ]));
	create_family("姑苏慕容",2,"传人");

        set("combat_exp", 1000000);
        set("score", 200000);

	set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
		(: perform_action,"unarmed.canhezhi" :),
		(: perform_action,"unarmed.tanyunshou" :),
        }) );

	set_skill("unarmed",150);
	set_skill("parry",150);
	set_skill("daoxuexinde",80);
	set_skill("foxuexinde",80);
	set_skill("dodge",150);
	set_skill("force",150);
	set_skill("literate",80);



	set_skill("murongquanfa",150);
	set_skill("murongxinfa",150);
	set_skill("murongshenfa",150);
	set_skill("douzhuanxingyi",150);
	map_skill("unarmed","murongquanfa");
	map_skill("parry","douzhuanxingyi");
	map_skill("force","murongxinfa");
	map_skill("dodge","murongshenfa");

        setup();
	carry_object(__DIR__"obj/shan")->wear();
}

void attempt_apprentice(object ob)
{
	if( ob->query("mingwang")<50000)	{
		command("say 我姑苏慕容弟子各各名震江湖，"+
	RANK_D->query_respect(ob)+"的名望还有待提高啊。");
                return;
        }
        command("say 很好，" + RANK_D->query_respect(ob) + 
"多加努力，他日必定有成。\n");
        command("recruit " + ob->query("id") );
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
			ob->set("class","xiake");
}
int do_go()
{
	object me=this_player();
	string fam;

	fam=(string)me->query("family/family_name");
	if( fam!="姑苏慕容")	{
		tell_object(me,"慕容复看了看你道：你想干什么？\n");
		return 1;
	}
	tell_object(me,"慕容复把你领进了密道后，转身离去。\n");
	me->move("/d/suzhou/midao2");
	return 1;
}

