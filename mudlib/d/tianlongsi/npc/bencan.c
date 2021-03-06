// bencan.c

inherit NPC;

void create()
{
	set_name("本参", ({ "ben can","can"}) );
	set("gender", "男性" );
	set("long", "他身材魁伟，为本因方丈的师兄。\n" );
	set("title", "天龙寺第十七代僧人");
	set("class", "bonze");
	set("age", 49);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);

	set("kee", 2500);
	set("max_kee", 2500);
	set("gin", 1000);
	set("max_gin", 1000);
	set("force", 2000);
	set("max_force", 2000);
	set("force_factor", 100);
	set("combat_exp", 800000);
	set("score", 1000000);

	set_skill("force", 120);
	set_skill("dodge", 180);
	set_skill("parry", 120);
	set_skill("unarmed", 185);
	set_skill("sword", 120);
	set_skill("tiannan-step", 180);
	set_skill("kurong-changong", 120);
	set_skill("duanjia-sword", 120);
	set_skill("liumai-shenjian", 180);

	set_skill("literate", 80);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("parry", "liumai-shenjian");
	map_skill("unarmed", "liumai-shenjian");
	map_skill("sword", "duanjia-sword");
	create_family("大理段家",17,"高僧");
	setup();
	carry_object("/obj/armor/jiasha")->wear();
}
#include <ben.h>
