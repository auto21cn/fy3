// yue-lingshan.c

inherit NPC;

void create()
{
        set_name("岳灵珊", ({ "yue lingshan", "yue", "lingshan" }) );
        set("nickname", "小师妹");
        set("gender", "女性" );
        set("age", 17);
        set("per", 29);
        set("str", 16);
        set("con", 24);
        set("dex", 30);
        set("int", 27);

        set("attitude", "friendly");

        set("max_kee",800);
        set("max_gin",500);
        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 80);
        set("combat_exp", 100000);

        set("long",     "岳灵珊是华山派掌门岳不群的独生女儿。\n");

        create_family("华山派", 14, "弟子");

	set_skill("unarmed",80);
	set_skill("sword",80);
	set_skill("force",80);
	set_skill("parry",80);
	set_skill("dodge",80);
        set_skill("literate", 70);

	set_skill("huashan-jianfa",80);
//      set_skill("yunu-sword", 80);
	set_skill("huashan-quanfa",80);
	set_skill("zixia-shengong",80);
	set_skill("feiyan-huixiang",80);

        map_skill("sword", "huashan-jianfa");
        map_skill("parry", "huashan-jianfa");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-quanfa");
        map_skill("dodge", "feiyan-huixiang");

        setup();

        carry_object(__DIR__"obj/green_water_sword")->wield();
        carry_object("/obj/cloth")->wear();

}

int accept_fight(object me)
{
        command("say 小女子怎会是你的对手?");
        return 0;
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
	if((string)ob->query("gender")=="女性" &&
                (string)ob->query("family/family_name")!="华山派")
        tell_object(ob,query("name")+"说道：这位"+
        RANK_D->query_respect(ob)+"可是来我华山拜师学艺的？\n");
        return;
}
void attempt_apprentice(object ob)
{
	string family;

	family=(string)ob->query("family/family_name");
	if((string)ob->query("gender")!="女性")
	command("say 咦？"+RANK_D->query_respect(ob)+
        "为何开如此玩笑？");
        else if((int)ob->query("mingwang")<0)
	command("say 我华山不收黑道上的人物。");
	else if(family=="华山派" && (int)ob->query("family/generation")<=(int)query("family/generation"))
	command("say 啊？这可不敢当。");
        else    {
        command("say 好吧，那我就收你为徒吧。");
        command("recruit " + ob->query("id") );
        ob->set("class","xiake");
        }
}

