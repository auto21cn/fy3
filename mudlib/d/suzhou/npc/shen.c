// woodcutter.c

inherit NPC;

void create()
{
	set_name("沈老财",({"shen laocai","shen","laocai"}));
	set("gender", "男性" );
	set("age",40);
	set("long","满面红光，一脸的福态。\n可见是个养尊处优之人。\n");
	set_skill("unarmed",40);
	set_skill("parry",40);
	set_skill("dodge",50);
	set_skill("sword",60);
	set("mingwang",-1);
	set("combat_exp",80000);
	set("str", 30);
	set("chat_chance",5);
	set("chat_msg", ({
		"沈老财说道：好好的干，我不会亏待大家的。\n",
		"沈老财道：只要我有饭吃，你们就饿不了。\n",
		"沈老财掏出摺扇轻轻的扇了两下。\n",
	}) );
	setup();
	carry_object(__DIR__"obj/sipao")->wear();
	carry_object(__DIR__"obj/zheshan")->wield();
	add_money("silver",10);
}
