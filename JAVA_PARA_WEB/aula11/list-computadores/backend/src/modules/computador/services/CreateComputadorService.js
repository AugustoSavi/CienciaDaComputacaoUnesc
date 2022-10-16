import AppError from "../../../shared/errors/AppError.js";

class CreateComputadorService {
    computadorRepository;

    constructor(computadorRepository) {
        this.computadorRepository = computadorRepository;
    }
    
    async execute({ hostname, processador, memoria, armazenamento, estado }) {
        const computadorAlreadyExist = await this.computadorRepository.findByHostname(hostname);
        if (computadorAlreadyExist) {
            throw new AppError('Já existe um computador com esse hostname');
        }

        return await this.computadorRepository.create({ hostname, processador, memoria, armazenamento, estado });
    }
}

export { CreateComputadorService };