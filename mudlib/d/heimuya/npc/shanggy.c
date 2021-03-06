//tonbaiwei.c
inherit NPC;

void greeting(object);
void init();
void create()
{
	set_name("上官云", ({ "shangguan yun","shangguan","yun"}) );
	set("gender", "男性" );
	set("age", 40);
	set("banghui" , "日月教");
	set("bh_rank","白虎堂长老");
	set("long", "他长手长脚, 双目精光灿然, 若有威势。\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("per", 21);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("chat_chance",5);
	set("chat_msg",({
"上官云沾沾自喜道：教主最近对我很赏识，看来要升职了。\n",
"上官云掂量一下手中的钢杖，嘿嘿冷笑两声。\n",
}));

	set("max_kee", 800);
	set("max_gin",800);
	set("force", 2000);
	set("max_force", 2000);
	set("force_factor", 200);
	set("combat_exp", 360000);
	set("score", 30000);
	set("mingwang",-30000);

	set_skill("force", 80);
	set_skill("dodge", 120);
	set_skill("unarmed", 80);
	set_skill("parry", 80);
	set_skill("staff",100);
	set_skill("hamagong",70);
	set_skill("chanchu-bufa", 120);
	set_skill("lingshe-zhangfa", 100);

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");
	
	setup();
         carry_object(__DIR__"obj/gangzhang")->wield();
         carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/zhenzhu");
	carry_object(__DIR__"obj/card2");

}



