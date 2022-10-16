class ListComputadoresService {
    computadorRepository;

    constructor(computadorRepository) {
        this.computadorRepository = computadorRepository;
    }

    execute() {
        return this.computadorRepository.list();
    }
}

export { ListComputadoresService };