import AppError from "../../../shared/errors/AppError.js";

class CreateHeroesService {
    heroesRepository;

    constructor(heroesRepository) {
        this.heroesRepository = heroesRepository;
    }
    
    async execute({name, slug, age}) {
        const heroAlreadyExist = await this.heroesRepository.findByName(name);

        if (heroAlreadyExist) {
            throw new AppError('Hero ja existe');
        }

        return await this.heroesRepository.create({name, slug, age});
    }
}

export { CreateHeroesService };