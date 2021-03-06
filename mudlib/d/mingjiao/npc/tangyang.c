#include "ansi.h"

inherit NPC;

void create()
{
        set_name("唐洋", ({ "tang yang","tang","yang",}));
        set("long",
        "他是一位高大魁伟的中年男子，身穿一件白布长袍。\n"
        "他手持钢刀，威风凛凛，有万夫不当之勇。\n"
        );

        set("banghui", "明教");
	set("bh_rank","洪水旗掌旗使");
        set("level",7);

        set("gender", "男性");
        set("attitude", "friendly");

        set("age", 40);
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("max_kee", 1000);
        set("max_gin", 1000);
        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 100);
        set("combat_exp", 100000);
        set("score", 5000);

        set_skill("force", 85);
        set_skill("hunyuan-yiqi", 85);
        set_skill("dodge", 85);
        set_skill("shaolin-shenfa", 85);
	set_skill("unarmed",90);
        set_skill("jingang-quan", 95);
        set_skill("parry", 85);
        set_skill("foxuexinde", 85);
        set_skill("literate", 85);

        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("parry", "jingang-quan");
	map_skill("unarmed","jingang-quan");


        setup();

//    carry_object("/d/mingjiao/obj/jiedao")->wield();
    carry_object("/d/mingjiao/obj/baipao")->wear();
}

