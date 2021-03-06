inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
void create()
{
        set_name("左冷禅", ({ "zuo lengchan", "zuo" }) );
        set("title", HIR"五岳剑派盟主"HIY"嵩山派第十三掌门"NOR);
        set("gender", "男性");
        set("class", "swordsman");
        set("age", 55);
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("force", 2400);
        set("max_force", 2400);
        set("force_factor", 30);
        set("max_kee",3000);
        set("max_gin",1200);
        set("combat_exp", 1200000);
        set("shen_type", -1);

        set_skill("unarmed", 220);
        set_skill("songyang-zhang",220);
        set_skill("sword", 220);
        set_skill("force", 220);
        set_skill("hanbing-zhenqi",220);
        set_skill("parry", 220);
        set_skill("dodge", 220);
        set_skill("songshan-jianfa", 220);
        set_skill("fuguanglueying", 220);
            set_skill("poyun-zhang", 220);

        map_skill("sword", "songshan-jianfa");
        map_skill("parry", "songshan-jianfa");
        map_skill("dodge", "fuguanglueying");
        map_skill("force","hanbing-zhenqi");
        map_skill("unarmed","poyun-zhang");

        create_family("嵩山派", 13, "掌门");
        setup();

carry_object("/obj/weapon/sword")->wield();
carry_object("/obj/cloth")->wear();
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

void greeting(object ob)
{
        string family;

        family=(string)ob->query("family/family_name");
        if(family=="嵩山派")
        command("say "+ob->query("name")+"，你要好好练功，为本派称霸江湖多出些力啊。");
        else    {
        command("say 哼，嵩山岂是你想来就来的地方。");
        kill_ob(ob);
        ob->fight_ob(this_object());
        }
}

void attempt_apprentice(object ob)
{
        string fam;

        fam=(string)ob->query("family/family_name");
        if(! fam || fam!="嵩山派")
        command("say 哼，本座可不敢收其他门派的弟子。");
        else if((int)ob->query("mingwang")>-10000)
        command("say 我嵩山弟子做事要心狠手辣，"+
        RANK_D->query_respect(ob)+"还做的不够啊。");
        else if((int)ob->query_skill("hanbing-zhenqi",1)<100)
        command("say 本门寒冰真气的心法，"+RANK_D->query_respect(ob)
        +"还要多花些功夫啊。");
        else    {
        command("say 呵呵，既然你如此诚心，那本座就收下你吧。");
       command("recruit " + ob->query("id") );
       ob->set("class","swordsman");
        }
}

