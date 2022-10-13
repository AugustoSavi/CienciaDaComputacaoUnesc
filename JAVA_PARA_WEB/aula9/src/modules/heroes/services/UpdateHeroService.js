class UpdateHeroService {
    heroesRepository;

    constructor(heroesRepository) {
        this.heroesRepository = heroesRepository;
    }
    
    async execute(id, {name, slug, age}) {
        const heroExist = await this.heroesRepository.findById(id);
        console.log(heroExist);
        if (!heroExist) {
            return {"Error": "Hero not exists"};
        }
        
        heroExist.name = name;
        heroExist.slug = slug;
        heroExist.age = age;
        heroExist.__v = heroExist.__v + 1;

        return await heroExist.save();
    }
}

export { UpdateHeroService };