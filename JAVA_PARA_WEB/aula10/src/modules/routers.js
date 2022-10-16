import { Router } from "express";

import { heroesRoutes } from "./heroes/routes/heroes.routes.js";

const router = Router();

router.use("/heroes", heroesRoutes);

export { router };
