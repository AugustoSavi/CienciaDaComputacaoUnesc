class FindOneHeroesService {
    heroesRepository;

    constructor(heroesRepository) {
        this.heroesRepository = heroesRepository;
    }

    execute(id) {
        return this.heroesRepository.findById(id);
    }
}

export { FindOneHeroesService };