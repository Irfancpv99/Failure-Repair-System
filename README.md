# System Repair Reliability Analysis with Mobius

## Project Overview

This repository contains a reliability and availability analysis of a critical failure-repair system using the Mobius modeling tool. The project was developed as part of the Architecture, Model and Analysis of Cyber-Physical Systems (AMA-CPS) course at the University of Florence.

## System Description

The system is modeled using a Reliability Block Diagram (RBD) with the following components:
- **Component A**: 1 unit with failure rate λ/4 and repair rate μ/4
- **Component B**: 2 units (B1, B2) with failure rate λ/2 and repair rate μ/2
- **Component C**: 3 units (C1, C2, C3) with failure rate λ and repair rate μ

The system fails when there is no path between source (s) and destination (d).

## System Configuration

This implementation analyzes the **R1-O1-W1** configuration:
- **R1**: Units cannot be repaired until the whole system fails
- **O1**: Sequential repair order: A → B1 → B2 → C1 → C2 → C3
- **W1**: System restarts working as soon as a path between s and d is restored

## Repository Structure

```
System Repair/
├── Atomic/
│   └── Repair/           # SAN (Stochastic Activity Network) model
│       ├── RepairSAN.cpp
│       ├── RepairSAN.h
│       └── Repair.san
├── Reward/
│   └── RW/              # Reward variables definition
│       ├── RWPVModel.cpp
│       ├── RWPVModel.h
│       └── RW.pvm
├── Study/
│   └── RS/              # Range study configurations
│       ├── RSRangeStudy.cpp
│       ├── RSRangeStudy.h
│       └── RS.rsd
├── Results/
│   ├── Reliability Matrix.xlsx
│   ├── Availability Matrix.xlsx
│   └── *.csv            # Experiment results
└── Documentation/
    ├── Project_Specification.pdf
    └── Project_Report.pdf
```

## Metrics Analyzed

### 1. Reliability
Probability that the system operates continuously without failure in the interval [0,t], given all units are working at t=0.

### 2. Steady-State Availability
Long-term measure of system operational readiness, accounting for both failures and repairs.

## Parameters

The analysis varies the following parameters:
- **λ (failure rate)**: 10⁻¹, 10⁻², 10⁻³ failures per hour
- **μ (repair rate)**: 10⁻¹, 10⁻², 10⁻³ repairs per hour
- **Time points**: 32, 280, 1200, 2480, 5240, 10520 hours (approximately 1, 15, 45, 105, 225, 465 days)

## Key Results

### Reliability Matrix (Sample at t=2480 hours)
| λ     | μ     | Reliability |
|-------|-------|------------|
| 10⁻¹  | 10⁻¹  | 0.0000     |
| 10⁻²  | 10⁻¹  | 0.0000     |
| 10⁻³  | 10⁻¹  | 0.7334     |
| 10⁻⁴  | 10⁻¹  | 0.9398     |

### Availability Matrix
| λ     | μ     | Steady-State Availability |
|-------|-------|--------------------------|
| 10⁻¹  | 10⁻¹  | 0.217                    |
| 10⁻²  | 10⁻¹  | 0.734                    |
| 10⁻³  | 10⁻¹  | 0.965                    |
| 10⁻⁴  | 10⁻¹  | 0.995                    |

## Tools and Technologies

- **Mobius 2.5**: Software tool for modeling complex system behavior
- **Solver**: Transient Solver (TRS) for instant-of-time analysis
- **Modeling Formalism**: Stochastic Activity Networks (SAN)

## How to Use

### Prerequisites
- Mobius 2.5 installed
- C++ compiler (for custom code compilation)

### Running the Model
1. Open the project in Mobius
2. Navigate to the Study module (RS)
3. Select experiments to run
4. Choose the Transient Solver for analysis
5. Execute and collect results

### Modifying Parameters
Edit the range study configuration in `Study/RS/` to adjust:
- Failure rates (λ)
- Repair rates (μ)
- Time points for analysis

## Key Findings

1. **Reliability decreases** exponentially with time, especially for higher failure rates
2. **Steady-state availability** improves significantly with:
   - Lower failure rates (smaller λ)
   - Higher repair rates (larger μ)
3. The sequential repair strategy (O1) with system-failure-triggered repair (R1) creates a trade-off between repair efficiency and system downtime

## Authors

**Cheriya Puthan Veettil Muhammed Irfan**  
Student ID: 7127908  
University of Florence

## Course Information

**Architecture, Model and Analysis of Cyber Physical Systems**  
Part II: Modeling and Analysis  
Academic Year: 2022-2023  
Professor: Paolo Lollini

## License

This project is part of academic coursework. Please refer to your institution's policies regarding code reuse and academic integrity.

## Acknowledgments

- Professor Paolo Lollini for project guidance
- University of Florence, Department of Computer Science
- Mobius tool development team at University of Illinois

## References

For more information about Mobius and numerical solvers:
- [Mobius Documentation](https://www.mobius.illinois.edu/wiki/)
- Course materials from AMA-CPS, University of Florence
