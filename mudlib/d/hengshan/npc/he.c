// he.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
void create()
{
        set_name("仪和", ({ "yi he", "he" }) );
        set("gender", "女性");
	set("class","nigu");
        set("age", 35);
        set("attitude", "peaceful");
        set("per", 24);
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("force", 1400);
        set("max_force", 1400);
        set("force_factor", 30);
        set("max_kee", 1000);
        set("max_gin", 800);
        set("combat_exp", 500000);
        set("shen_type", 1);

        set_skill("unarmed", 90);
        set_skill("sword", 90);
        set_skill("force", 90);
        set_skill("parry", 90);
        set_skill("dodge", 90);
        set_skill("hengshan-jianfa", 90);
        set_skill("lingxu-bufa", 90);
	set_skill("lingyuan-xinfa",90);

	map_skill("force","lingyuan-xinfa");
        map_skill("sword", "hengshan-jianfa");
        map_skill("parry", "hengshan-jianfa");
        map_skill("dodge", "lingxu-bufa");

        create_family("恒山派", 14, "弟子");
        setup();

carry_object("/obj/weapon/sword")->wield();
carry_object("/d/dali/npc/obj/cheng-cloth")->wear();
}

