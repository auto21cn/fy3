// guard.c

#include <ansi.h>

inherit NPC;
int do_func();

void create()
{
	set_name("崔百泉",({"cui baiquan","cui","baiquan"}));
	set("title","金算盘");
	set("gender", "男性" );
	set("age",43);
	set("str",50);
	set("mingwang",-1);
	set("cor", 30);
	set("cps", 30);
	set("int",30);
	set("con",50);
	set("long",
	"人长得精瘦，看不出哪点象习武之人，倒象个痨病鬼一般。\n"
	);
	set("per",10);
	set("no_get",1);
	set("chat_chance",2);
        set("chat_msg", ({
	"崔百泉骂道：“姑苏慕容一家老小也不知死到哪去了。”\n",
	"崔百泉自言自语道：“老子找了半天，也不知燕子坞这个鸟地方在哪。”\n",
	"崔百泉嘴里嘟嘟囔囔，也不知说些什么，你只隐约听到「姑苏慕容」什么的。\n",
		}));
	set("combat_exp",20000);
	set_temp("apply/attack",40);
	set_temp("apply/defense",30);
	set_skill("blade",50);

	set("attitude", "heroism");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
	"崔百泉骂道：杀慕容一家老小之前，先拿你开刀吧！\n",
	"崔百泉喊道：你和姑苏慕容是什么关系！\n",
	"崔百泉叫道：要不是老子的称手兵刃掉进河里，哪里轮到你在此猖狂！\n",
	}) );
	set("inquiry", ([
	"姑苏慕容" : (:do_func:),
	"燕子坞" :"老子打听了半天，居然没一个人知道这个鸟地方在哪。\n",
	]) );


	set_skill("dodge",50);
	set_skill("parry", 50);
	
	setup();
	
	carry_object("/obj/weapon/blade")->wield();
	carry_object("/obj/cloth")->wear();
}
int do_func()
{
	object ob,npc;
	command("say 老子是来找他报仇的！\n");
	npc=present("a bi",environment());
	if(!npc)	{
		ob=new(__DIR__"abi.c");
	write("这时，湖中少女划着小船已近岸边。\n");
		write("她似乎听到了什么，冲你微微一笑。\n");
	ob->move(environment());
			    }
	return 1;
}
