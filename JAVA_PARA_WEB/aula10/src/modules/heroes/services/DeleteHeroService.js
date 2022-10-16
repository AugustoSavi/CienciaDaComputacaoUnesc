import AppError from "../../../shared/errors/AppError.js";

class DeleteHeroService {
    heroesRepository;

    constructor(heroesRepository) {
        this.heroesRepository = heroesRepository;
    }
    
    async execute(id) {
        const heroExist = await this.heroesRepository.findById(id);
        if (!heroExist) {
            throw new AppError('Hero não existe');
        }
        return await heroExist.remove();
    }
}

export { DeleteHeroService };