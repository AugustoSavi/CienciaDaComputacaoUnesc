class FindOneComputadorService {
    computadorRepository;

    constructor(computadorRepository) {
        this.computadorRepository = computadorRepository;
    }

    execute(id) {
        return this.computadorRepository.findById(id);
    }
}

export { FindOneComputadorService };